#include "yaShader.h"

namespace ya
{
	Shader::Shader()
	{
	}
	Shader::~Shader()
	{
	}
	HRESULT Shader::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	bool Shader::Create(const eShaderStage stage, const std::wstring& filename, const std::string& funcName)
	{
		std::filesystem::path shaderPath = std::filesystem::current_path().parent_path();
		shaderPath += L"\\Shader_Source\\";

		std::filesystem::path fullPath(shaderPath.c_str());
		fullPath += filename;

		ID3DBlob* errorBlob = nullptr;
		if (stage == eShaderStage::VS)
		{
			GetDevice()->CompileFromfile(fullPath, funcName, "vs_5_0", mVSBlob.GetAddressOf());
			GetDevice()->CreateVertexShader(mVSBlob->GetBufferPointer()
				, mVSBlob->GetBufferSize(), mVS.GetAddressOf());
		}
		else if (stage == eShaderStage::PS)
		{
			GetDevice()->CompileFromfile(fullPath, funcName, "ps_5_0", mPSBlob.GetAddressOf());
			GetDevice()->CreatePixelShader(mPSBlob->GetBufferPointer()
				, mPSBlob->GetBufferSize(), mPS.GetAddressOf());
		}


		return true;
	}
	void Shader::Binds()
	{
		GetDevice()->BindVertexShader(mVS.Get());
		GetDevice()->BindPixelShader(mPS.Get());
	}
}