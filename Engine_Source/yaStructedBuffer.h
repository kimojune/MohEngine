#pragma once
#include "yaEntity.h"
#include "yaGraphics.h"

namespace ya::graphics
{
	class StructedBuffer : public GpuBuffer
	{
	public:
		StructedBuffer();
		~StructedBuffer();

		bool Create(UINT size, UINT stride, eSRVType type);
		void SetData(void* data, UINT stride);
		void Bind(eShaderStage stage, UINT slot);

		UINT Getsize() { return mSize; }
		UINT GetStride() { return mStride; }

	private:
		Microsoft::WRL::ComPtr <ID3D11ShaderResourceView> mSRV;
		eSRVType mType;

		//Å©±â
		UINT mSize;
		//°¹¼ö(?)
		UINT mStride;

	};
}
