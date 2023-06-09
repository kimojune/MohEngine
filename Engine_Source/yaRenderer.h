#pragma once
#include "MohEngine.h"
#include "yaGraphicDevice_Dx11.h"
#include "yaMesh.h"
#include "yaShader.h"
#include "yaConstantBuffer.h"

using namespace ya::math;
namespace ya::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertexes[];
	extern ya::Mesh* mesh;
	extern ya::graphics::ConstantBuffer* constantBuffer;
	extern ya::graphics::ConstantBuffer* constantBuffer2;
	extern ya::Shader* shader;
	
	void Initialize();
	void Release();


}