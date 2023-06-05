#include "yaGraphicDevice_Dx11.h"
#include "yaApplication.h"
#include "yaRenderer.h"

extern ya::Application application;

namespace ya::graphics
{
	GraphicDevice_Dx11::GraphicDevice_Dx11()
	{
		//device, context 생성
		HWND hWnd = application.GetHwnd();
		UINT flag = D3D11_CREATE_DEVICE_DEBUG;
		D3D_FEATURE_LEVEL feature_level = (D3D_FEATURE_LEVEL)0;

		D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr,flag
			, nullptr, 0, D3D11_SDK_VERSION, mDevice.GetAddressOf()
			, &feature_level, mContext.GetAddressOf());



		//SwapChain
		DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
		swapChainDesc.BufferCount = 2;
		swapChainDesc.BufferDesc.Width= application.GetWidth();
		swapChainDesc.BufferDesc.Height = application.GetHeight();

		if (!CreateSwapChain(&swapChainDesc, hWnd))
			return;

		if (FAILED(mSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)mRenderTarget.GetAddressOf())))
			return;;

		mDevice->CreateRenderTargetView(mRenderTarget.Get(), nullptr, mRenderTargetView.GetAddressOf());



		D3D11_TEXTURE2D_DESC depthStencilDesc{};
		depthStencilDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL;
		depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
		depthStencilDesc.CPUAccessFlags = 0;

		depthStencilDesc.Format = DXGI_FORMAT::DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilDesc.Width = application.GetWidth();
		depthStencilDesc.Height = application.GetHeight();
		depthStencilDesc.ArraySize = 1;
		depthStencilDesc.SampleDesc.Count = 1;
		depthStencilDesc.SampleDesc.Quality = 0;

		depthStencilDesc.MipLevels = 0;
		depthStencilDesc.MiscFlags = 0;

		D3D11_SUBRESOURCE_DATA data;

		if (!CreateTexture(&depthStencilDesc, &data))
			return;

		RECT winRect = {};
		GetClientRect(hWnd, &winRect);

	//typedef struct D3D11_VIEWPORT
	//{
	//	FLOAT TopLeftX;
	//	FLOAT TopLeftY;
	//	FLOAT Width;
	//	FLOAT Height;
	//	FLOAT MinDepth;
	//	FLOAT MaxDepth;
	//} 	D3D11_VIEWPORT;

		mViewPort =
		{
			0.0f, 0.0f
			, (float)(winRect.right - winRect.left)
			, (float)(winRect.bottom - winRect.top)
			, 0.0f, 1.0f
		};

		BindViewPort(&mViewPort);

		mContext->OMSetRenderTargets(1, mRenderTargetView.GetAddressOf(), mDepthStencilView.Get());
	}

	GraphicDevice_Dx11::~GraphicDevice_Dx11()
	{
	}
	bool GraphicDevice_Dx11::CreateSwapChain(const DXGI_SWAP_CHAIN_DESC* desc, HWND hWnd)
	{
		DXGI_SWAP_CHAIN_DESC dxgiDesc = {};

		dxgiDesc.OutputWindow = hWnd;
		dxgiDesc.Windowed = true;
		dxgiDesc.SwapEffect = DXGI_SWAP_EFFECT::DXGI_SWAP_EFFECT_DISCARD;
		dxgiDesc.BufferCount = desc->BufferCount;


		dxgiDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		dxgiDesc.BufferDesc.Width = desc->BufferDesc.Width;
		dxgiDesc.BufferDesc.Height = desc->BufferDesc.Height;
		dxgiDesc.BufferDesc.Format = DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM;
		dxgiDesc.BufferDesc.RefreshRate.Numerator = 144;
		dxgiDesc.BufferDesc.RefreshRate.Denominator = 1;
		dxgiDesc.BufferDesc.Scaling = DXGI_MODE_SCALING::DXGI_MODE_SCALING_UNSPECIFIED; // 모니터의 해상도에 맞게 이미지가 늘어나는 방식
		dxgiDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER::DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED; //래스터가 이미지를 생성하는데 사용하는 방법
		
		
		dxgiDesc.SampleDesc.Count = 1;
		dxgiDesc.SampleDesc.Quality = 0;
		
		Microsoft::WRL::ComPtr<IDXGIDevice> pDXGIDevice = nullptr;
		Microsoft::WRL::ComPtr<IDXGIAdapter> pAdapter= nullptr;
		Microsoft::WRL::ComPtr<IDXGIFactory> pFactory = nullptr;

		if (FAILED(mDevice->QueryInterface(__uuidof(IDXGIDevice),(void**) pDXGIDevice.GetAddressOf())))
			return false;

		if (FAILED(pDXGIDevice->GetParent(__uuidof(IDXGIAdapter), (void**)pAdapter.GetAddressOf())))
			return false;

		if(FAILED(pAdapter->GetParent(__uuidof(IDXGIFactory),(void**)pFactory.GetAddressOf())))
			return false;

		if (FAILED(pFactory->CreateSwapChain(mDevice.Get(), &dxgiDesc, mSwapChain.GetAddressOf())))
			return false;

		return true;
	}
	bool GraphicDevice_Dx11::CreateBuffer(ID3D11Buffer** buffer, D3D11_BUFFER_DESC* desc, D3D11_SUBRESOURCE_DATA* data)
	{
		if (FAILED(mDevice->CreateBuffer(desc, data, buffer)))
			return false;

		return true;
	}
	bool GraphicDevice_Dx11::CreateShader()
	{
		//ID3DBlob* vsBlob = nullptr;
		//std::filesystem::path shaderPath = std::filesystem::current_path().parent_path();
		//shaderPath += L"\\Shader_Source\\";

		//std::filesystem::path vsPath(shaderPath.c_str());
		//vsPath += L"TriangleVS.hlsl";

		//D3DCompileFromFile(vsPath.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE
		//	, "main", "vs_5_0", 0, 0, &ya::renderer::triangleVSBlob, &ya::renderer::errorBlob);

		//if (ya::renderer::errorBlob)
		//{
		//	OutputDebugStringA((char*)ya::renderer::errorBlob->GetBufferPointer());
		//	ya::renderer::errorBlob->Release();
		//}

		//mDevice->CreateVertexShader(ya::renderer::triangleVSBlob->GetBufferPointer()
		//	, ya::renderer::triangleVSBlob->GetBufferSize()
		//	, nullptr, &ya::renderer::triangleVSShader);

		//std::filesystem::path psPath(shaderPath.c_str());
		//psPath += L"TrianglePS.hlsl";

		//D3DCompileFromFile(psPath.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE
		//	, "main", "ps_5_0", 0, 0, &ya::renderer::trianglePSBlob, &ya::renderer::errorBlob);

		//if (ya::renderer::errorBlob)
		//{
		//	OutputDebugStringA((char*)ya::renderer::errorBlob->GetBufferPointer());
		//	ya::renderer::errorBlob->Release();
		//}

 	//	mDevice->CreatePixelShader(ya::renderer::trianglePSBlob->GetBufferPointer()
		//	, ya::renderer::trianglePSBlob->GetBufferSize()
		//	, nullptr, &ya::renderer::trianglePSShader);

		//D3D11_INPUT_ELEMENT_DESC arrLayout[2] = {};

		//arrLayout[0].AlignedByteOffset = 0;
		//arrLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		//arrLayout[0].InputSlot = 0;
		//arrLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		//arrLayout[0].SemanticName = "POSITION";
		//arrLayout[0].SemanticIndex = 0;
		//	  
		//arrLayout[1].AlignedByteOffset = 12;
		//arrLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		//arrLayout[1].InputSlot = 0;
		//arrLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		//arrLayout[1].SemanticName = "COLOR";
		//arrLayout[1].SemanticIndex = 0;

		//mDevice->CreateInputLayout(arrLayout, 2
		//	, renderer::triangleVSBlob->GetBufferPointer()
		//	, renderer::triangleVSBlob->GetBufferSize()
		//	, &renderer::triangleLayout);
		//
		return true;
	}
	bool GraphicDevice_Dx11::CompileFromfile(const std::wstring& fileName, const std::string& funcName, const std::string& version, ID3DBlob** ppCode)
	{
		ID3DBlob* errorBlob = nullptr;
		D3DCompileFromFile(fileName.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE
			, funcName.c_str(), version.c_str(), 0, 0, ppCode, &errorBlob);

		if (errorBlob)
		{
			OutputDebugStringA((char*)(errorBlob->GetBufferPointer()));
			errorBlob->Release();
			errorBlob = nullptr;
		}

		return false;
	}
	bool GraphicDevice_Dx11::CreateVertexShader(const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11VertexShader** ppVertexShader)
	{
		if (FAILED(mDevice->CreateVertexShader(pShaderBytecode, BytecodeLength, nullptr, ppVertexShader)))
			return false;

		return true;
	}
	bool GraphicDevice_Dx11::CreatePixelShader(const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11PixelShader** ppPixelShader)
	{
		if (FAILED(mDevice->CreatePixelShader(pShaderBytecode, BytecodeLength, nullptr, ppPixelShader)))
			return false;

		return true;
	}
	bool GraphicDevice_Dx11::CreateTexture(const D3D11_TEXTURE2D_DESC* desc, void* date)
	{
		D3D11_TEXTURE2D_DESC dxgiDesc = {};
		dxgiDesc.BindFlags = desc->BindFlags;
		dxgiDesc.Usage = desc->Usage;
		dxgiDesc.CPUAccessFlags = 0;

		dxgiDesc.Format = desc->Format;
		dxgiDesc.Width = desc->Width;
		dxgiDesc.Height = desc->Height;
		dxgiDesc.ArraySize = desc->ArraySize;

		dxgiDesc.SampleDesc.Count = desc->SampleDesc.Count;
		dxgiDesc.SampleDesc.Quality= 0;

		dxgiDesc.MipLevels = desc->MipLevels;
		dxgiDesc.MiscFlags = desc->MiscFlags;

		if (FAILED(mDevice->CreateTexture2D(&dxgiDesc, nullptr, mDepthStencilBuffer.ReleaseAndGetAddressOf())))
			return false;

		if (FAILED(mDevice->CreateDepthStencilView(mDepthStencilBuffer.Get(), nullptr, mDepthStencilView.GetAddressOf())))
			return false;		

		return true;
	}
	void GraphicDevice_Dx11::BindViewPort(D3D11_VIEWPORT* viewport)
	{
		mContext->RSSetViewports(1, viewport);
	}

	void GraphicDevice_Dx11::BindVertexBuffer(UINT StartSlot, ID3D11Buffer* const* ppVertexBuffers, const UINT* pStrides, const UINT* pOffsets)
	{
		mContext->IASetVertexBuffers(StartSlot, 1, ppVertexBuffers, pStrides, pOffsets);
	}

	void GraphicDevice_Dx11::BindIndexBuffer(ID3D11Buffer* pIndexBuffer, DXGI_FORMAT Format, UINT Offset)
	{
		mContext->IASetIndexBuffer(pIndexBuffer, Format, Offset);
	}

	void GraphicDevice_Dx11::BindVertexShader(ID3D11VertexShader* pVetexShader)
	{
		mContext->VSSetShader(pVetexShader, 0, 0);
	}

	void GraphicDevice_Dx11::BindPixelShader(ID3D11PixelShader* pPixelShader)
	{
		mContext->PSSetShader(pPixelShader, 0, 0);
	}

	void GraphicDevice_Dx11::SetConstantBuffer(ID3D11Buffer* buffer, void* data, UINT size)
	{
		D3D11_MAPPED_SUBRESOURCE subRes = {};
		mContext->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &subRes);
		memcpy(subRes.pData, data, size);
		mContext->Unmap(buffer, 0);
	}

	void GraphicDevice_Dx11::BindConstantBuffer(eShaderStage stage, eCBType type, ID3D11Buffer* buffer)
	{
		switch (stage)
		{
		case eShaderStage::VS:
			mContext->VSSetConstantBuffers((UINT)type, 1, &buffer);
			break;
		case eShaderStage::HS:
			mContext->HSSetConstantBuffers((UINT)type, 1, &buffer);
			break;
		case eShaderStage::DS:
			mContext->DSSetConstantBuffers((UINT)type, 1, &buffer);
			break;
		case eShaderStage::GS:
			mContext->GSSetConstantBuffers((UINT)type, 1, &buffer);
			break;
		case eShaderStage::PS:
			mContext->PSSetConstantBuffers((UINT)type, 1, &buffer);
			break;
		case eShaderStage::CS:
			mContext->CSSetConstantBuffers((UINT)type, 1, &buffer);
			break;
		case eShaderStage::End:
			break;
		default:
			break;
		}
	}

	void GraphicDevice_Dx11::BindsConstantBuffer(eShaderStage stage, eCBType type, ID3D11Buffer* buffer)
	{
		mContext->VSSetConstantBuffers((UINT)type, 1, &buffer);
		mContext->HSSetConstantBuffers((UINT)type, 1, &buffer);
		mContext->DSSetConstantBuffers((UINT)type, 1, &buffer);
		mContext->GSSetConstantBuffers((UINT)type, 1, &buffer);
		mContext->PSSetConstantBuffers((UINT)type, 1, &buffer);
		mContext->CSSetConstantBuffers((UINT)type, 1, &buffer);
	}

	void GraphicDevice_Dx11::Draw()
	{
		//reder target clear
		FLOAT bgcolor[4] = {0.2f,0.2f,0.2f,1.0f};
		mContext->ClearRenderTargetView(mRenderTargetView.Get(), bgcolor);
		mContext->ClearDepthStencilView(mDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0.0f);

		//view port update
		HWND hWnd = application.GetHwnd();
		RECT winRect = {};
		GetClientRect(hWnd, &winRect);
		
		mViewPort =
		{
			0.0f, 0.0f
			, (float)(winRect.right - winRect.left)
			, (float)(winRect.bottom - winRect.top)
			, 0.0f, 1.0f
		};

		BindViewPort(&mViewPort);
		mContext->OMSetRenderTargets(1, mRenderTargetView.GetAddressOf(), mDepthStencilView.Get());

		renderer::mesh->BindBuffer();

		mContext->IASetInputLayout(renderer::triangleLayout);
		mContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		//Bind VS,PS
		renderer::shader->Binds();

		// Draw Render Target
		//mContext->Draw(9, 0);
		mContext->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
		// 레더타겟에 있는 이미지를 화면에 그려준다
		mSwapChain->Present(0, 0);
	}
}
