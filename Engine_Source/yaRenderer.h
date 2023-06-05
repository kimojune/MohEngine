#pragma once
#include "MohEngine.h"
#include "yaGraphicDevice_Dx11.h"
#include "yaMesh.h"
#include "yaShader.h"

using namespace ya::math;
namespace ya::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertexes[];
	extern ID3D11InputLayout* triangleLayout;
	extern ya::Mesh* mesh;
	extern ID3D11Buffer* triangleConstantBuffer;

	extern ya::Shader* shader;
	extern ID3D11PixelShader* trianglePSShader;

	void Initialize();
	void Release();
}