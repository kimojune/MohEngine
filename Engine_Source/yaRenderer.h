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
		Vector2 uv;
	};

	extern Vertex vertexes[];
	extern ya::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End];
	
	
	void Initialize();
	void Release();
}