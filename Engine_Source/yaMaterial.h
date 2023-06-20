#pragma once
#include "yaResource.h"
#include "yaShader.h"
#include "yaTexture.h"

namespace ya::graphics
{
	class Material : public Resource
	{
	public:
		Material();
		~Material();

		virtual HRESULT Load(const std::wstring& path) override;

		void Binds();

		void SetShader(Shader* shader) { mShader = shader; }
		void SetTexture(Texture* texture) { mTexture = texture; }

	private:
		Shader* mShader;
		Texture* mTexture;
	};
}