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

		bool Create(UINT width, UINT height, DXGI_FORMAT format, UINT bingFlag);
		virtual HRESULT Load(const std::wstring& path) override;
		HRESULT CreateTex(const std::wstring& path, UINT filecnt, size_t imageMaxWidth, size_t imageMaxHeight, UINT maxIndex = 1 );
		
		void CreateAtlas(const std::wstring& path, UINT maxIndex = 1);
		void BindShader(eShaderStage stage, UINT startSlot);
		void Clear();

		math::Vector2 GetSize()
		{
			return math::Vector2((float)mImage.GetImages()->width, ((float)mImage.GetImages()->height));
		}
		float GetWidth() { return (float)mImage.GetImages()->width; }
		float GetHeight() { return (float)mImage.GetImages()->height; }

		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>    GetRTV() { return  mRTV; }
		void SetRTV(Microsoft::WRL::ComPtr<ID3D11RenderTargetView> rtv) { mRTV = rtv; }
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView>    GetDSV() { return  mDSV; }
		void SetDSV(Microsoft::WRL::ComPtr<ID3D11DepthStencilView> dsv) { mDSV = dsv; }
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>  GetSRV() { return  mSRV; }
		Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> GetUAV() { return  mUAV; }
		Microsoft::WRL::ComPtr<ID3D11Texture2D> GetTexture() { return mTexture; }
		void SetTexture(Microsoft::WRL::ComPtr<ID3D11Texture2D> texture) { mTexture = texture; }


		UINT GetmaxX() { return maxX; }
		UINT GetmaxY() { return maxY; }

	private:
		ScratchImage mImage;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mTexture;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mSRV;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mRTV;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mDSV;
		Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> mUAV;
		D3D11_TEXTURE2D_DESC mDesc;

		UINT maxY;
		UINT maxX;
	};

}
