#pragma once
#include "MohEngine.h"

#include <d3d11.h>
#include <d3dcompiler.h>

#pragma commnet(lib,"d3d11.lib")
#pragma commnet(lib,"d3compiler.lib")

namespace ya::graphics
{

class GraphicDevice_Dx11
{
public:
	GraphicDevice_Dx11();
	~GraphicDevice_Dx11();

private:
	//���� �׷���ī�� ��ü
	Microsoft::WRL::ComPtr<ID3D11Device>mDevice;

	// DX11������ ���������� ����̽� ��ü�� �������� �ʰ�
	// �� ��ü�� �̿��Ͽ� ����� ������.
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>mContext;

	//���������� �׷��� �ؽ��� (��ȭ��)
	Microsoft::WRL::ComPtr<ID3D11Texture2D>mRenderTarget;

	//����Ÿ�ٿ� ���� �������� �ʰ� ����Ÿ�ٺ並 �̿��Ͽ� �����Ѵ�
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>mRenderTargetView;

	//���̹���
	Microsoft::WRL::ComPtr<ID3D11Texture2D>mDepthStencilBuffer;

	//���� ���ۿ� ���� �� �� �ִ� ��
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView>mDepthStencilView;

	//���� ���۸� �۾��� �������ִ� swapchain
	Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain;
		

};

}
