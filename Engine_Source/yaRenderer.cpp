#include "yaRenderer.h"
#include "yaResources.h"
#include "yaTexture.h"
#include "yaMaterial.h"

namespace ya::renderer
{
	Vertex vertexes[4] = {};

	ya::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[(UINT)eSamplerType::End] = {};

	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRSType::End];
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDSType::End];
	Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBSType::End];

	std::vector<ya::Camera*> cameras = {};

	void SetupState()
	{

#pragma region InputLayout

		// Input layout 정점 구조 정보를 넘겨줘야한다.
		D3D11_INPUT_ELEMENT_DESC arrLayout[3] = {};

		arrLayout[0].AlignedByteOffset = 0;
		arrLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		arrLayout[0].InputSlot = 0;
		arrLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[0].SemanticName = "POSITION";
		arrLayout[0].SemanticIndex = 0;

		arrLayout[1].AlignedByteOffset = 12;
		arrLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		arrLayout[1].InputSlot = 0;
		arrLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[1].SemanticName = "COLOR";
		arrLayout[1].SemanticIndex = 0;

		arrLayout[2].AlignedByteOffset = 28;
		arrLayout[2].Format = DXGI_FORMAT_R32G32_FLOAT;
		arrLayout[2].InputSlot = 0;
		arrLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[2].SemanticName = "TEXCOORD";
		arrLayout[2].SemanticIndex = 0;


		std::shared_ptr<Shader> shader = ya::Resources::Find<Shader>(L"TriangleShader");
		
		ya::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());

		shader = ya::Resources::Find<Shader>(L"SpriteShader");
		ya::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());

		shader = ya::Resources::Find<Shader>(L"GridShader");
		ya::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());

#pragma endregion
#pragma region Sampler State
		//Sampler State
		D3D11_SAMPLER_DESC samplerDesc = {};
		samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		GetDevice()->CreateSamplerState(&samplerDesc, samplerState[(UINT)eSamplerType::Point].GetAddressOf());
		GetDevice()->BindSampler(eShaderStage::PS, 0, samplerState[(UINT)eSamplerType::Point].GetAddressOf());

		samplerDesc.Filter = D3D11_FILTER_ANISOTROPIC;
		GetDevice()->CreateSamplerState(&samplerDesc, samplerState[(UINT)eSamplerType::Anisotropic].GetAddressOf());
		GetDevice()->BindSampler(eShaderStage::PS, 1, samplerState[(UINT)eSamplerType::Anisotropic].GetAddressOf());
#pragma endregion
#pragma region Rasterizer State
		//Rasterizer State
		D3D11_RASTERIZER_DESC rasterizerDesc = {};
		

		rasterizerDesc.FillMode = D3D11_FILL_SOLID;
		rasterizerDesc.CullMode = D3D11_CULL_BACK;
		GetDevice()->CreateRasterizerState(&rasterizerDesc, rasterizerStates[(UINT)eRSType::SolidBack].GetAddressOf());

		rasterizerDesc.FillMode = D3D11_FILL_SOLID;
		rasterizerDesc.CullMode = D3D11_CULL_FRONT;
		GetDevice()->CreateRasterizerState(&rasterizerDesc, rasterizerStates[(UINT)eRSType::SolidFront].GetAddressOf());
		
		rasterizerDesc.FillMode = D3D11_FILL_SOLID;
		rasterizerDesc.CullMode = D3D11_CULL_NONE;
		GetDevice()->CreateRasterizerState(&rasterizerDesc, rasterizerStates[(UINT)eRSType::SolidNone].GetAddressOf());
		
		rasterizerDesc.FillMode = D3D11_FILL_WIREFRAME;
		rasterizerDesc.CullMode = D3D11_CULL_NONE;
		GetDevice()->CreateRasterizerState(&rasterizerDesc, rasterizerStates[(UINT)eRSType::WireframeNone].GetAddressOf());
#pragma endregion 
#pragma region Depth Stencil State
		D3D11_DEPTH_STENCIL_DESC depthstencildesc = {};

		//less
		depthstencildesc.DepthEnable = true;
		depthstencildesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS;
		depthstencildesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthstencildesc.StencilEnable = false;
		GetDevice()->CreateDepthStencilState(&depthstencildesc, depthStencilStates[(UINT)eDSType::Less].GetAddressOf());
		

		//greater
		depthstencildesc.DepthEnable = true;
		depthstencildesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_GREATER;
		depthstencildesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthstencildesc.StencilEnable = false;
		GetDevice()->CreateDepthStencilState(&depthstencildesc, depthStencilStates[(UINT)eDSType::Greater].GetAddressOf());
		

		//No write
		depthstencildesc.DepthEnable = true;
		depthstencildesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS;
		depthstencildesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		depthstencildesc.StencilEnable = false;
		GetDevice()->CreateDepthStencilState(&depthstencildesc, depthStencilStates[(UINT)eDSType::NoWrite].GetAddressOf());

		//None
		depthstencildesc.DepthEnable = false;
		depthstencildesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS;
		depthstencildesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		depthstencildesc.StencilEnable = false;
		GetDevice()->CreateDepthStencilState(&depthstencildesc, depthStencilStates[(UINT)eDSType::None].GetAddressOf());
#pragma endregion
#pragma region Blend State
		D3D11_BLEND_DESC blendDesc = {};

		//default
		blendStates[(UINT)eBSType::Default] = nullptr;

		//Alpha Blend
		blendDesc.AlphaToCoverageEnable = false;
		blendDesc.IndependentBlendEnable = false;
		blendDesc.RenderTarget[0].BlendEnable = true;
		blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

		GetDevice()->CreateBlendState(&blendDesc, blendStates[(UINT)eBSType::AlphaBlend].GetAddressOf());

		// one one
		blendDesc.AlphaToCoverageEnable = false;
		blendDesc.IndependentBlendEnable = false;

		blendDesc.RenderTarget[0].BlendEnable = true;
		blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		GetDevice()->CreateBlendState(&blendDesc
			, blendStates[(UINT)eBSType::OneOne].GetAddressOf());
#pragma endregion

	}
	
	void LoadMesh()
	{
		//RECT
		vertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[0].uv = Vector2(0.0f, 0.0f);

		vertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[1].uv = Vector2(1.0f, 0.0f);

		vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[2].uv = Vector2(1.0f, 1.0f);

		vertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		vertexes[3].uv = Vector2(0.0f, 1.0f);
	}

	void LoadBuffer()
	{
		std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		Resources::Insert(L"RectMesh", mesh);

		mesh->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes = {};
		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);
		
		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);

		mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		//constant Buffer
		constantBuffer[(UINT)eCBType::Transform] = new ya::graphics::ConstantBuffer(eCBType::Transform);
		constantBuffer[(UINT)eCBType::Transform]->Create(sizeof(TransformCB));

		constantBuffer[(UINT)eCBType::Grid] = new ya::graphics::ConstantBuffer(eCBType::Grid);
		constantBuffer[(UINT)eCBType::Grid]->Create(sizeof(TransformCB));
	}

	void LoadShader()
	{		
		std::shared_ptr<Shader>  shader = std::make_shared<Shader>();
		shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
		ya::Resources::Insert(L"TriangleShader", shader);
		
		shader = std::make_shared<Shader>();
		shader->Create(eShaderStage::VS, L"SpriteVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"SpritePS.hlsl", "main");
		ya::Resources::Insert(L"SpriteShader", shader);

		shader = std::make_shared<Shader>();
		shader->Create(eShaderStage::VS, L"GridVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"GridPS.hlsl", "main");
		ya::Resources::Insert(L"GridShader", shader);
	}

	void LoadMaterial()
	{
		std::shared_ptr<Shader> spriteShader
			= Resources::Find<Shader>(L"SpriteShader");

		std::shared_ptr<Texture> texture
			= Resources::Load<Texture>(L"Link", L"..\\Resources\\Texture\\Link.png");

		std::shared_ptr<Material> material = std::make_shared<Material>();
		material->SetShader(spriteShader);
		material->SetTexture(texture);
		Resources::Insert(L"SpriteMaterial", material);

		texture = Resources::Load<Texture>(L"Smile", L"..\\Resources\\Texture\\Smile.png");
		material = std::make_shared<Material>();
		material->SetShader(spriteShader);
		material->SetTexture(texture);
		material->SetRenderingMode(eRenderingMode::Transparent);
		Resources::Insert(L"SpriteMaterial02", material);

		std::shared_ptr<Shader> gridShader
			= Resources::Find<Shader>(L"GridShader");

		material = std::make_shared<Material>();
		material->SetShader(gridShader);
		Resources::Insert(L"GridMaterial", material);
	}

	void Initialize()
	{
		LoadMesh();
		LoadBuffer();
		LoadShader();
		SetupState();
		LoadMaterial();
	}
	void Render()
	{
		for (Camera* cam : cameras)
		{
			if (cam == nullptr)
				continue;

			cam->Render();
		}

		cameras.clear();
	}
	void Release()
	{
		for (ConstantBuffer* buff : constantBuffer)
		{
			if (buff == nullptr)
				continue;
			
			delete buff;
			buff = nullptr;
		}
	}
}
