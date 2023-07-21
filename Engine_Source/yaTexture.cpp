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

	//std::shared_ptr<Texture> Texture::CreateTextureSheet(const std::wstring& name, const std::wstring& path)
	//{
	//	UINT width = 0;
	//	UINT height = 0;
	//	UINT fileCount = 0;

	//	std::filesystem::path fs(path);
	//	std::vector<std::shared_ptr<Texture>> textures = {};
	//	for (const auto& p : std::filesystem::directory_iterator(path))
	//	{
	//		std::wstring fileName = p.path().filename();
	//		std::wstring grandparentName = p.path().parent_path().parent_path();
	//		std::wstring fullName = path + L"\\" + fileName;
	//		std::wstring keyName = fullName.erase(0, grandparentName.length());

	//		const std::wstring ext = p.path().extension();
	//		if (ext != L".png")
	//			continue;

	//		//textures = Resources::
	//		std::shared_ptr<Texture> texture = Resources::Load<Texture>(keyName, fullName);

	//		textures.push_back(texture);
	//		if (width < texture->GetWidth())
	//		{
	//			width = texture->GetWidth();
	//		}
	//		if (height < texture->GetHeight())
	//		{
	//			height = texture->GetHeight();
	//		}
	//		fileCount++;


	//	}
	//	
	//	D3D11_TEXTURE2D_DESC textureDesc = {};
	//	textureDesc.Width = width * fileCount;
	//	textureDesc.Height = 1024;
	//	textureDesc.MipLevels = 1;
	//	textureDesc.ArraySize = 1;
	//	textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	//	textureDesc.SampleDesc.Count = 1;
	//	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	//	textureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

	//	std::shared_ptr<Texture> texture;
	//	
	//	return texture;
	//}
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