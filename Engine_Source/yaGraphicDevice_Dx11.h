#pragma once
#include "MohEngine.h"

#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")


namespace ya::graphics
{

class GraphicDevice_Dx11
{
public:
	GraphicDevice_Dx11();
	~GraphicDevice_Dx11();

	bool CreateSwapChain(const DXGI_SWAP_CHAIN_DESC* desc, HWND hWnd);
	bool CreateBuffer(ID3D11Buffer** buffer,D3D11_BUFFER_DESC* desc, D3D11_SUBRESOURCE_DATA* data);
	bool CreateShader();

	bool CreateTexture(const D3D11_TEXTURE2D_DESC* desc, void* date);

	void BindViewPort(D3D11_VIEWPORT* viewport);

	void Draw();


private:
	//실제 그래픽카드 객체
	Microsoft::WRL::ComPtr<ID3D11Device>mDevice;

	// DX11에서는 직접적으로 디바이스 객체에 접근하지 않고
	// 이 객체를 이용하여 명령을 내린다.
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>mContext;

	//최종적으로 그려질 텍스쳐 (도화지)
	Microsoft::WRL::ComPtr<ID3D11Texture2D>mRenderTarget;

	//랜더타겟에 직접 접근하지 않고 랜더타겟뷰를 이용하여 접근한다
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>mRenderTargetView;

	//깊이버퍼
	Microsoft::WRL::ComPtr<ID3D11Texture2D>mDepthStencilBuffer;

	//깊이 버퍼에 접근 할 수 있는 뷰
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView>mDepthStencilView;

	//더블 버퍼링 작업을 진행해주는 swapchain
	Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain;
	
	D3D11_VIEWPORT mViewPort;

};

inline GraphicDevice_Dx11*& GetDevice()
{
	static GraphicDevice_Dx11* device = nullptr;
	return device;
}

}
