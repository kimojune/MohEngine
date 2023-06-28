#pragma once
#include "yaResources.h"
#include "yaTexture.h"
#include "yaMaterial.h"
#include "yaShader.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\MohEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\MohEngine.lib")
#endif



namespace ya
{
	void CreateMaterial()
	{

		std::shared_ptr<Shader> spriteShader = Resources::Find<Shader>(L"SpriteShader");
		
		std::shared_ptr<ya::graphics::Texture> texture 
			= Resources::Load<ya::graphics::Texture>(L"guide_idle", L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\front\\guide_idle_front_001.png");

		std::shared_ptr<Material>  spriteMaterial = std::make_shared<Material>();
		spriteMaterial->SetShader(spriteShader);
		spriteMaterial->SetTexture(texture);
		Resources::Insert(L"guide_Material", spriteMaterial);
	
	}

	void CreateTexture()
	{

	}
}