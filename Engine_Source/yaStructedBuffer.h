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

		bool Create(UINT size, UINT stride, eViewType type, void* data);
		void SetData(void* data, UINT buffercount);
		void BindSRV(eShaderStage stage, UINT slot);
		void BindUAV(UINT slot);

		void Clear();

		UINT Getsize() { return mSize; }
		UINT GetStride() { return mStride; }

	private:
		Microsoft::WRL::ComPtr <ID3D11ShaderResourceView> mSRV;
		Microsoft::WRL::ComPtr <ID3D11UnorderedAccessView> mUAV;
		eViewType mType;

		//Å©±â
		UINT mSize;
		//°¹¼ö(?)
		UINT mStride;

		UINT mSRVSlot;
		UINT mUAVSlot;

	};
}
