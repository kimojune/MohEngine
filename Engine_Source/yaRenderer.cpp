#include "yaRenderer.h"
#include "yaResources.h"
#include "yaTexture.h"
#include "yaMaterial.h"
#include "yaStructedBuffer.h"
#include "yaPaintShader.h"

namespace ya::renderer
{
	ya::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[(UINT)eSamplerType::End] = {};

	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRSType::End];
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDSType::End];
	Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBSType::End];

	// light
	std::vector<Light*> lights = {};
	StructedBuffer* lightsBuffer = nullptr;

	// camera
	ya::Camera* mainCamera = nullptr;
	std::vector<ya::Camera*> cameras = {};
	std::vector<DebugMesh> debugMeshes = {};

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

		shader = ya::Resources::Find<Shader>(L"TileShader");
		ya::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());
		
		shader = ya::Resources::Find<Shader>(L"DebugShader");
		ya::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());

		shader = ya::Resources::Find<Shader>(L"AnimatorShader");
		ya::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());

		shader = ya::Resources::Find<Shader>(L"testShader");
		ya::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());
		
		shader = ya::Resources::Find<Shader>(L"ParticleShader");
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
		depthstencildesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS_EQUAL;
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
		std::vector<Vertex> vertexes = {};
		std::vector<Vertex> tilevertexes = {};
		std::vector<Vertex> testvertexes = {};
		std::vector<UINT> indexes = {};
		//PointMesh
		Vertex v = {};
		v.pos = Vector3(0.0f, 0.0f, 0.0f);
		vertexes.push_back(v);
		indexes.push_back(0);
		std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		mesh->CreateVertexBuffer(vertexes.data(), vertexes.size());
		mesh->CreateIndexBuffer(indexes.data(), indexes.size());
		Resources::Insert(L"PointMesh", mesh);

		vertexes.clear();
		indexes.clear();

		//RECT
		vertexes.resize(4);
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

		//Vertex Buffer
		mesh = std::make_shared<Mesh>();
		Resources::Insert(L"RectMesh", mesh);
		mesh->CreateVertexBuffer(vertexes.data(), vertexes.size());

		//tile Mesh
		tilevertexes.resize(4);
		std::shared_ptr<Mesh> tilemesh = std::make_shared<Mesh>();
		Resources::Insert(L"TileMesh", tilemesh);

		tilevertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		tilevertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		tilevertexes[0].uv = Vector2(0.0f, 0.0f);

		tilevertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		tilevertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		tilevertexes[1].uv = Vector2(0.03125f, 0.0f);

		tilevertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		tilevertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		tilevertexes[2].uv = Vector2(0.03125f, 0.03125f);

		tilevertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		tilevertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		tilevertexes[3].uv = Vector2(0.0f, 0.03125f);

		tilemesh->CreateVertexBuffer(tilevertexes.data(), tilevertexes.size());
		
		testvertexes.resize(4);
		testvertexes[0].pos = Vector3(0.0f, 1.0f, 0.0f);
		testvertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		testvertexes[0].uv = Vector2(0.0f, 0.0f);
		
		testvertexes[1].pos = Vector3(1.0f, 1.0f, 0.0f);
		testvertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		testvertexes[1].uv = Vector2(1.0f, 0.0f);
		
		testvertexes[2].pos = Vector3(1.0f, 0.0f, 0.0f);
		testvertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		testvertexes[2].uv = Vector2(1.0f, 1.0f);
		
		testvertexes[3].pos = Vector3(0.0f, 0.0f, 0.0f);
		testvertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		testvertexes[3].uv = Vector2(0.0f, 1.0f);

		std::shared_ptr<Mesh> testmesh = std::make_shared<Mesh>();
		Resources::Insert(L"testMesh", testmesh);
		testmesh->CreateVertexBuffer(testvertexes.data(), testvertexes.size());

		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);
		
		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);

		mesh->CreateIndexBuffer(indexes.data(), indexes.size());
		tilemesh->CreateIndexBuffer(indexes.data(), indexes.size());
		testmesh->CreateIndexBuffer(indexes.data(), indexes.size());


		// Rect Debug Mesh
		std::shared_ptr<Mesh> rectDebug = std::make_shared<Mesh>();
		Resources::Insert(L"DebugRect", rectDebug);
		rectDebug->CreateVertexBuffer(vertexes.data(), vertexes.size());
		rectDebug->CreateIndexBuffer(indexes.data(), indexes.size());

		// Circle Debug Mesh
		vertexes.clear();
		indexes.clear();

		Vertex center = {};
		center.pos = Vector3(0.0f, 0.0f, 0.0f);
		center.color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes.push_back(center);

		int iSlice = 40;
		float fRadius = 0.5f;
		float fTheta = XM_2PI / (float)iSlice;

		for (int i = 0; i < iSlice; ++i)
		{
			center.pos = Vector3(fRadius * cosf(fTheta * (float)i)
				, fRadius * sinf(fTheta * (float)i)
				, 0.0f);
			center.color = Vector4(0.0f, 1.0f, 0.0f, 1.f);
			vertexes.push_back(center);
		}


		for (int i = 0; i < vertexes.size() - 2; ++i)
		{
			indexes.push_back(i + 1);
		}
		indexes.push_back(1);

		std::shared_ptr<Mesh> circleDebug = std::make_shared<Mesh>();
		Resources::Insert(L"DebugCircle", circleDebug);
		circleDebug->CreateVertexBuffer(vertexes.data(), vertexes.size());
		circleDebug->CreateIndexBuffer(indexes.data(), indexes.size());
	}

	void LoadBuffer()
	{
		//constant Buffer
		constantBuffer[(UINT)eCBType::Transform] = new ya::graphics::ConstantBuffer(eCBType::Transform);
		constantBuffer[(UINT)eCBType::Transform]->Create(sizeof(TransformCB));

		constantBuffer[(UINT)eCBType::Grid] = new ya::graphics::ConstantBuffer(eCBType::Grid);
		constantBuffer[(UINT)eCBType::Grid]->Create(sizeof(TransformCB));

		constantBuffer[(UINT)eCBType::Animator] = new ya::graphics::ConstantBuffer(eCBType::Animator);
		constantBuffer[(UINT)eCBType::Animator]->Create(sizeof(AnimatorCB));

		// light structed Buffer
		lightsBuffer = new StructedBuffer();
		lightsBuffer->Create(sizeof LightAttribute, 2, eSRVType::None);
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
		
		shader = std::make_shared<Shader>();
		shader->Create(eShaderStage::VS, L"TileVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"TilePS.hlsl", "main");
		ya::Resources::Insert(L"TileShader", shader);

		shader = std::make_shared<Shader>();
		shader->Create(eShaderStage::VS, L"SpriteVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"AnimationPS.hlsl", "main");
		ya::Resources::Insert(L"AnimatorShader", shader);

		shader = std::make_shared<Shader>();
		shader->Create(eShaderStage::VS, L"SpriteVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"testPS.hlsl", "main");
		ya::Resources::Insert(L"testShader", shader);

		std::shared_ptr<Shader> debugShader = std::make_shared<Shader>();
		debugShader->Create(eShaderStage::VS, L"DebugVS.hlsl", "main");
		debugShader->Create(eShaderStage::PS, L"DebugPS.hlsl", "main");
		debugShader->SetTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		debugShader->SetRSState(eRSType::WireframeNone);
		//debugShader->SetDSState(eDSType::NoWrite);
		ya::Resources::Insert(L"DebugShader", debugShader);


		std::shared_ptr<PaintShader> paintShader = std::make_shared<PaintShader>();
		paintShader->Create(L"PaintCS.hlsl", "main");
		ya::Resources::Insert(L"PaintShader", paintShader);
		
		std::shared_ptr<Shader> particleShader = std::make_shared<Shader>();
		particleShader->Create(eShaderStage::VS, L"ParticleVS.hlsl", "main");
		particleShader->Create(eShaderStage::PS, L"ParticlePS.hlsl", "main");
		particleShader->Create(eShaderStage::GS, L"ParticleGS.hlsl", "main");
		particleShader->SetRSState(eRSType::SolidNone);
		particleShader->SetDSState(eDSType::NoWrite);
		particleShader->SetBSState(eBSType::AlphaBlend);
		particleShader->SetTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D_PRIMITIVE_TOPOLOGY_POINTLIST);

		ya::Resources::Insert(L"ParticleShader", particleShader);
	}

	void LoadTexture()
	{
		//paint texture
		std::shared_ptr<Texture> uavTexture = std::make_shared<Texture>();
		uavTexture->Create(1024, 1024, DXGI_FORMAT_R8G8B8A8_UNORM, D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS);
		ya::Resources::Insert(L"PaintTexuture", uavTexture);


	}
	void LoadMaterial()
	{
		std::shared_ptr<Shader> shader
			= Resources::Find<Shader>(L"SpriteShader");

		std::shared_ptr<Texture> texture
			= Resources::Load<Texture>(L"Link", L"..\\Resources\\Texture\\Link.png");

		std::shared_ptr<Material> material = std::make_shared<Material>();
		material->SetShader(shader);
		material->SetTexture(texture);
		Resources::Insert(L"SpriteMaterial", material);	
		
		std::shared_ptr<Shader> animatorShader
			= Resources::Find<Shader>(L"AnimatorShader");
		material = std::make_shared<Material>();
		material->SetShader(animatorShader);
		material->SetTexture(texture);
		Resources::Insert(L"AnimatorMaterial", material);


		texture = Resources::Find<Texture>(L"PaintTexuture");
		material = std::make_shared<Material>();
		material->SetShader(shader);
		material->SetTexture(texture);
		material->SetRenderingMode(eRenderingMode::Transparent);
		Resources::Insert(L"SpriteMaterial02", material);

		//texture = Resources::Load<Texture>(L"Smile", L"..\\Resources\\Texture\\Smile.png");
		//material = std::make_shared<Material>();
		//material->SetShader(shader);
		//material->SetTexture(texture);
		//material->SetRenderingMode(eRenderingMode::Transparent);
		//Resources::Insert(L"SpriteMaterial02", material);

		std::shared_ptr<Shader> gridShader
			= Resources::Find<Shader>(L"GridShader");

		material = std::make_shared<Material>();
		material->SetShader(gridShader);
		Resources::Insert(L"GridMaterial", material);

		std::shared_ptr<Shader> debugShader
			= Resources::Find<Shader>(L"DebugShader");

		material = std::make_shared<Material>();
		material->SetShader(debugShader);
		Resources::Insert(L"DebugMaterial", material);

		shader
			= Resources::Find<Shader>(L"ParticleShader");
		material = std::make_shared<Material>();
		material->SetShader(shader);
		material->SetRenderingMode(eRenderingMode::Transparent);
		Resources::Insert(L"ParticleMaterial", material);
	}

	void Initialize()
	{
		LoadMesh();
		LoadBuffer();
		LoadShader();
		SetupState();
		LoadTexture();
		LoadMaterial();
	}

	void BindLights()
	{
		std::vector<LightAttribute> lightAttributes = {};
		for (Light* light : lights)
		{
			LightAttribute attribute = light->GetAttibute();
			lightAttributes.push_back(attribute);
		}

		lightsBuffer->SetData(lightAttributes.data(), lightAttributes.size());
		lightsBuffer->Bind(eShaderStage::VS, 13);
		lightsBuffer->Bind(eShaderStage::PS, 13);
	}
	void Render()
	{
		BindLights();

		for (Camera* cam : cameras)
		{
			if (cam == nullptr)
				continue;

			cam->Render();
		}

		cameras.clear();
		lights.clear();
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

		delete lightsBuffer;
		lightsBuffer = nullptr;
	}
	void PushDebugMeshAttribute(DebugMesh& mesh)
	{
		debugMeshes.push_back(mesh);
	}
}
