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

	void CreateMaterial(const std::wstring& shadername, std::shared_ptr<ya::graphics::Texture> texture, const std::wstring& materialname)
	{
		std::shared_ptr<Shader> spriteShader = Resources::Find<Shader>(shadername);

		std::shared_ptr<Material>  spriteMaterial = std::make_shared<Material>();
		spriteMaterial->SetShader(spriteShader);
		spriteMaterial->SetTexture(texture);
		Resources::Insert(materialname, spriteMaterial);
	}

	void LoadMaterial()
	{
		std::shared_ptr<ya::graphics::Texture> guide_idle_front_001
			= Resources::Load<ya::graphics::Texture>(L"guide_idle_front_001", L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\front\\guide_idle_front_001.png");
		
		CreateMaterial(L"SpriteShader", guide_idle_front_001, L"guide_Material");

		std::shared_ptr<ya::graphics::Texture> marsh_of_gungeon_001
			= Resources::Load<ya::graphics::Texture>(L"marsh_of_gungeon_001", L"..\\Resources\\Texture\\TitleScreenCollection\\marsh_of_gungeon_001.png");

		CreateMaterial(L"SpriteShader", marsh_of_gungeon_001, L"marsh_of_gungeon_material");

		std::shared_ptr<ya::graphics::Texture> silhouette_lich_bot_idle_001
			= Resources::Load<ya::graphics::Texture>(L"silhouette_lich_bot_idle_001", L"..\\Resources\\Texture\\TitleScreenCollection\\silhouette_lich_bot_idle_001.png");

		CreateMaterial(L"SpriteShader", silhouette_lich_bot_idle_001, L"silhouette_lich_bot_material");
		
		std::shared_ptr<ya::graphics::Texture> silhouette_lich_top_windy_001
			= Resources::Load<ya::graphics::Texture>(L"silhouette_lich_top_windy_001", L"..\\Resources\\Texture\\TitleScreenCollection\\silhouette_lich_top_windy_001.png");
		CreateMaterial(L"SpriteShader", silhouette_lich_top_windy_001, L"silhouette_lich_top_windy_material");
		
		std::shared_ptr<ya::graphics::Texture> cheapo_cloud_001
			= Resources::Load<ya::graphics::Texture>(L"cheapo_cloud_001", L"..\\Resources\\Texture\\TitleScreenCollection\\cheapo_cloud_001.png");
		CreateMaterial(L"SpriteShader", cheapo_cloud_001, L"cheapo_cloud_001_material");
		
		std::shared_ptr<ya::graphics::Texture> cheapo_cloud_002
			= Resources::Load<ya::graphics::Texture>(L"cheapo_cloud_002", L"..\\Resources\\Texture\\TitleScreenCollection\\cheapo_cloud_002.png");
		CreateMaterial(L"SpriteShader", cheapo_cloud_002, L"cheapo_cloud_002_material");
		
		std::shared_ptr<ya::graphics::Texture> silhouette_lich_click_001
			= Resources::Load<ya::graphics::Texture>(L"silhouette_lich_click_001", L"..\\Resources\\Texture\\TitleScreenCollection\\silhouette_lich_click_001.png");
		CreateMaterial(L"SpriteShader", silhouette_lich_click_001, L"silhouette_lich_click_Material");
		

		std::shared_ptr<ya::graphics::Texture> title_water_001
			= Resources::Load<ya::graphics::Texture>(L"title_water_001", L"..\\Resources\\Texture\\TitleScreenCollection\\title_water_001.png");
		CreateMaterial(L"SpriteShader", title_water_001, L"title_water_001_material");
		
		//std::shared_ptr<ya::graphics::Texture> title_water_001
		//	= Resources::Load<ya::graphics::Texture>(L"title_water_001", L"..\\Resources\\Texture\\TitleScreenCollection\\title_water_001.png");
		//CreateMaterial(L"SpriteShader", title_water_001, L"title_water_001_material");
		
		std::shared_ptr<ya::graphics::Texture> marsh_of_gungeon_glow_001
			= Resources::Load<ya::graphics::Texture>(L"marsh_of_gungeon_glow_001", L"..\\Resources\\Texture\\TitleScreenCollection\\marsh_of_gungeon_glow_001.png");
		CreateMaterial(L"SpriteShader", marsh_of_gungeon_glow_001, L"marsh_of_gungeon_glow_001_material");
		
		std::shared_ptr<ya::graphics::Texture> flag_wave_001
			= Resources::Load<ya::graphics::Texture>(L"flag_wave_001", L"..\\Resources\\Texture\\TitleScreenCollection\\flag_wave_001.png");
		CreateMaterial(L"SpriteShader", flag_wave_001, L"flag_wave_001_material");
		
		std::shared_ptr<ya::graphics::Texture> title_words_black_001
			= Resources::Load<ya::graphics::Texture>(L"title_words_black_001", L"..\\Resources\\Texture\\TitleScreenCollection\\title_words_black_001.png");
		CreateMaterial(L"SpriteShader", title_words_black_001, L"title_words_black_001_material");

		


	
		

	}

}