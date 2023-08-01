#include "yaTexture.h"
#include "yaGraphicDevice_Dx11.h"
#include "yaResources.h"

namespace ya::graphics
{
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
		, mImage{}
		, mTexture(nullptr)
		, mSRV(nullptr)
		, mDesc{}
		, maxY(0)
		, maxX(0)
	{
	}

	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		wchar_t szExtension[50] = {};
		//경로를 나누어 저장해주는 함수
		_wsplitpath_s(path.c_str(), nullptr, 0, nullptr, 0, nullptr, 0, szExtension, 50);

		std::wstring extension = szExtension;
		if (extension == L".dds" || extension == L".DDS")
		{
			if (FAILED(LoadFromDDSFile(path.c_str(), DDS_FLAGS::DDS_FLAGS_NONE, nullptr, mImage)))
				return S_FALSE;
		}
		else if (extension == L".tga" || extension == L".TGA")
		{
			if (FAILED(LoadFromTGAFile(path.c_str(), nullptr, mImage)))
				return S_FALSE;
		}
		else // WIC (png, jpg, jpeg, bmp )
		{
			//if (FAILED(LoadFromWICFile(path.c_str(), WIC_FLAGS::WIC_FLAGS_NONE, nullptr, mImage)))
			if (FAILED(LoadFromWICFile(path.c_str(), WIC_FLAGS::WIC_FLAGS_IGNORE_SRGB, nullptr, mImage)))
				return S_FALSE;
		}

		CreateShaderResourceView
		(
			GetDevice()->GetID3D11Device()
			, mImage.GetImages()
			, mImage.GetImageCount()
			, mImage.GetMetadata()
			, mSRV.GetAddressOf()
		);
		mSRV->GetResource((ID3D11Resource**)mTexture.GetAddressOf());

		return S_OK;
	}

	HRESULT Texture::CreateTex(const std::wstring& path, UINT filecnt, size_t imageMaxWidth, size_t imageMaxHeight, UINT maxIndex)
	{
		if (filecnt == 0)
			return E_INVALIDARG;

		ScratchImage atlasImage;
		HRESULT hr = S_OK;

		wchar_t ext[_MAX_EXT] = {};

		ScratchImage image;
		UINT idx = 0;
		bool isMake = false;
		std::filesystem::path fs(path);
		for (const auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = p.path().wstring(); // Use the full path from the iterator
			
			_wsplitpath_s(fileName.c_str(), nullptr, 0, nullptr, 0, nullptr, 0, ext, _MAX_EXT);

			if (_wcsicmp(ext, L".ini") == 0)
				continue;

			if (_wcsicmp(ext, L".dds") == 0)
			{
				hr = LoadFromDDSFile(fullName.c_str(), DDS_FLAGS_NONE, nullptr, image);
			}
			else if (_wcsicmp(ext, L".tga") == 0)
			{
				hr = LoadFromTGAFile(fullName.c_str(), nullptr, image);
			}
			else if (_wcsicmp(ext, L".hdr") == 0)
			{
				hr = LoadFromHDRFile(fullName.c_str(), nullptr, image);
			}
			else
			{
				hr = LoadFromWICFile(fullName.c_str(), WIC_FLAGS_NONE, nullptr, image);
			}

			if (SUCCEEDED(hr))
			{
				// Convert the image to a different format if needed (e.g., to DXGI_FORMAT_R8G8B8A8_UNORM)
				ScratchImage convertedImage;
				hr = Convert(image.GetImages(), image.GetImageCount(), image.GetMetadata()
					, DXGI_FORMAT_R8G8B8A8_UNORM, TEX_FILTER_DEFAULT, TEX_THRESHOLD_DEFAULT, convertedImage);
				if (FAILED(hr))
				{
					// Handle the conversion error if necessary
					return hr;
				}
				if (isMake == false)
				{
					if (maxIndex == 1)
					{
						maxX = filecnt;
						maxY = 1;
					}
					else
					{
						maxX = maxIndex;
						maxY = filecnt / maxIndex;
					}

					if (filecnt == 1)
						hr = atlasImage.Initialize2D(DXGI_FORMAT_R8G8B8A8_UNORM, imageMaxWidth , imageMaxHeight , 1, 1);

					else
					hr = atlasImage.Initialize2D(DXGI_FORMAT_R8G8B8A8_UNORM, imageMaxWidth * maxX, imageMaxHeight * maxY, 1, 1);
				
					isMake = true;
				}
				if (FAILED(hr))
				{
					// Handle the atlas image initialization error if necessary
					return hr;
				}
				
				UINT mY = idx / maxIndex;
				UINT mX = idx % maxIndex;

				if (maxIndex == 1)
				{
					hr = CopyRectangle(*convertedImage.GetImage(0, 0, 0), Rect(0, 0, convertedImage.GetMetadata().width, convertedImage.GetMetadata().height),
						*atlasImage.GetImage(0, 0, 0), TEX_FILTER_DEFAULT, (imageMaxWidth)*idx, 0);
				}

				else
				{
					hr = CopyRectangle(*convertedImage.GetImage(0, 0, 0), Rect(0, 0, convertedImage.GetMetadata().width, convertedImage.GetMetadata().height),
						*atlasImage.GetImage(0, 0, 0), TEX_FILTER_DEFAULT, (imageMaxWidth)* mX, imageMaxHeight * mY);
				}
				//(imageMaxWidth)*idx, 0);
				if (FAILED(hr))
				{
					// Handle the copy rectangle error if necessary
					return hr;
				}
			}
			idx++;
		}
		if (FAILED(hr))
		{
			// Error handling if image loading, conversion, or copy rectangle fails
			return hr;
		}


		CreateShaderResourceView
		(
			GetDevice()->GetID3D11Device()
			, atlasImage.GetImages()
			, atlasImage.GetImageCount()
			, atlasImage.GetMetadata()
			, mSRV.GetAddressOf()
		);
		mSRV->GetResource((ID3D11Resource**)mTexture.GetAddressOf());

		// Create an atlas texture object
		// Assign the DirectX 11 texture and SRV to the atlasTexture

		// Copy the image data from atlasImage to atlasTexture->mImage
		this->mImage.Initialize2D(
			atlasImage.GetMetadata().format,
			atlasImage.GetMetadata().width,
			atlasImage.GetMetadata().height,
			atlasImage.GetMetadata().arraySize,
			atlasImage.GetMetadata().mipLevels
		);

		return S_OK;
	}

	void Texture::CreateAtlas(const std::wstring& path, UINT maxIndex)
	{
		size_t maxwidth = 0;
		size_t maxheight = 0;
		UINT fileCount = 0;

		std::filesystem::path fs(path);
		std::vector<std::shared_ptr<graphics::Texture>> textures = {};
		for (const auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			//std::wstring fileName = p.path().filename();
			//std::wstring fullName = p.path().wstring(); // Use the full path from the iterator

			//const std::wstring ext = p.path().extension();

			//std::shared_ptr<graphics::Texture> tex = Resources::Load<graphics::Texture>(fileName, fullName);


			//textures.push_back(tex);

			fileCount++;
		}

		std::wstring key = fs.parent_path().filename();
		key += fs.filename();

		CreateTex(path, fileCount, TILE_SIZE_X, TILE_SIZE_Y, maxIndex);

		//return std::make_shared<Texture> ;
	}

	void Texture::BindShader(eShaderStage stage, UINT startSlot)
	{
		GetDevice()->BindShaderResource(stage, startSlot, mSRV.GetAddressOf());
	}
	void Texture::Clear()
	{
		ID3D11ShaderResourceView* srv = nullptr;

		GetDevice()->BindShaderResource(eShaderStage::VS, 0, &srv);
		GetDevice()->BindShaderResource(eShaderStage::DS, 0, &srv);
		GetDevice()->BindShaderResource(eShaderStage::GS, 0, &srv);
		GetDevice()->BindShaderResource(eShaderStage::HS, 0, &srv);
		GetDevice()->BindShaderResource(eShaderStage::CS, 0, &srv);
		GetDevice()->BindShaderResource(eShaderStage::PS, 0, &srv);
	}
}