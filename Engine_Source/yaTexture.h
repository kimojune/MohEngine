#pragma once
#include "yaResource.h"
#include "yaGraphics.h"

#include "../External/DirectXTex/Include/DirectXTex.h"
#include "../External/DirectXTex/Include/DirectXTex.inl"

#ifdef _DEBUG
#pragma comment(lib, "..\\External\\DirectXTex\\Lib\\Debug\\DirectXTex.lib")
#else
#pragma comment(lib, "..\\External\\DirectXTex\\Lib\\Release\\DirectXTex.lib")
#endif

namespace ya::graphics
{
	class Texture : public  Resource
	{
	public:
		struct SpriteInfo
		{
				
		};

		Texture();
		~Texture();


		virtual HRESULT Load(const std::wstring& path) override;
		HRESULT CreateTex(const std::wstring& path, UINT filecnt, size_t imageMaxWidth, size_t imageMaxHeight);
		
		//T CreateAtlas((const std::wstring& path, UINT filecnt, size_t imageMaxWidth, size_t imageMaxHeight));

		void BindShader(eShaderStage stage, UINT startSlot);

		void Clear();

		math::Vector2 GetSize()
		{
			return math::Vector2((float)mImage.GetImages()->width, ((float)mImage.GetImages()->height));
		}
		float GetWidth() { return (float)mImage.GetImages()->width; }
		float GetHeight() { return (float)mImage.GetImages()->height; }

	private:
		ScratchImage mImage;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mTexture;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mSRV;
		D3D11_TEXTURE2D_DESC mDesc;

	};

}
