#pragma once
#include "..\Engine_SOURCE\yaResources.h"
#include "..\Engine_SOURCE\yaTexture.h"
#include "..\Engine_SOURCE\yaMaterial.h"
#include "..\Engine_SOURCE\yaShader.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\MohEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\MohEngine.lib")
#endif


//#include "yaResources.h"
//#include "yaTexture.h"
//#include "yaMaterial.h"
//#include "yaShader.h"


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
	void CreateMaterial(const std::wstring& shadername, std::shared_ptr<ya::graphics::Texture> texture, const std::wstring& materialname, eRenderingMode mode)
	{
		std::shared_ptr<Shader> spriteShader = Resources::Find<Shader>(shadername);

		std::shared_ptr<Material>  spriteMaterial = std::make_shared<Material>();
		spriteMaterial->SetShader(spriteShader);
		spriteMaterial->SetTexture(texture);
		spriteMaterial->SetRenderingMode(mode);
		Resources::Insert(materialname, spriteMaterial);
	}

	void LoadMaterial()
	{
		std::shared_ptr<ya::graphics::Texture> MagentaTexture
			= Resources::Load<ya::graphics::Texture>(L"MagentaTexture", L"..\\Resources\\Texture\\MagentaTexture.png");
		CreateMaterial(L"SpriteShader", MagentaTexture, L"MagentaTexture_material");

		std::shared_ptr<ya::graphics::Texture> guide_idle_front_001
			= Resources::Load<ya::graphics::Texture>(L"guide_idle_front_001", L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\front\\guide_idle_front_001.png");
		CreateMaterial(L"SpriteShader", guide_idle_front_001, L"guide_idle_front_001_material");

		std::shared_ptr<ya::graphics::Texture> dog_idle_left_001
			= Resources::Load<ya::graphics::Texture>(L"dog_idle_left_001", L"..\\Resources\\Texture\\Charactor\\The Hunter\\Companions\\idle_left\\dog_idle_left_001.png");
		
		CreateMaterial(L"SpriteShader", dog_idle_left_001, L"dog_idle_left_001_material");

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
		
		std::shared_ptr<ya::graphics::Texture> marsh_of_gungeon_glow_001
			= Resources::Load<ya::graphics::Texture>(L"marsh_of_gungeon_glow_001", L"..\\Resources\\Texture\\TitleScreenCollection\\marsh_of_gungeon_glow_001.png");
		CreateMaterial(L"SpriteShader", marsh_of_gungeon_glow_001, L"marsh_of_gungeon_glow_001_material");
		
		std::shared_ptr<ya::graphics::Texture> flag_wave_001
			= Resources::Load<ya::graphics::Texture>(L"flag_wave_001", L"..\\Resources\\Texture\\TitleScreenCollection\\flag_wave_001.png");
		CreateMaterial(L"SpriteShader", flag_wave_001, L"flag_wave_001_material");
		
		std::shared_ptr<ya::graphics::Texture> title_words_black_001
			= Resources::Load<ya::graphics::Texture>(L"title_words_black_001", L"..\\Resources\\Texture\\TitleScreenCollection\\title_words_black_001.png");
		CreateMaterial(L"SpriteShader", title_words_black_001, L"title_words_black_001_material");

		std::shared_ptr<ya::graphics::Texture> dragun_title_screen_001
			= Resources::Load<ya::graphics::Texture>(L"dragun_title_screen_001", L"..\\Resources\\Texture\\TitleScreenCollection\\dragun_title_screen_001.png");
		CreateMaterial(L"SpriteShader", dragun_title_screen_001, L"dragun_title_screen_001_material");
		
		std::shared_ptr<ya::graphics::Texture> reticle_crosshair_002
			= Resources::Load<ya::graphics::Texture>(L"reticle_crosshair_002", L"..\\Resources\\Texture\\UI\\reticle_crosshair_002.png");
		CreateMaterial(L"SpriteShader", reticle_crosshair_002, L"reticle_crosshair_002_material");
		
		std::shared_ptr<ya::graphics::Texture> HP_effect
			= Resources::Load<ya::graphics::Texture>(L"HP_effect", L"..\\Resources\\Texture\\UI\\GameUI\\HP_effect.png");
		CreateMaterial(L"SpriteShader", HP_effect, L"HP_effect_material");

		std::shared_ptr<ya::graphics::Texture> Heart
			= Resources::Load<ya::graphics::Texture>(L"Heart", L"..\\Resources\\Texture\\UI\\GameUI\\Heart.png");
		CreateMaterial(L"SpriteShader", Heart, L"Heart_material");
		
		std::shared_ptr<ya::graphics::Texture> ui_key
			= Resources::Load<ya::graphics::Texture>(L"ui_key", L"..\\Resources\\Texture\\UI\\GameUI\\ui_key.png");
		CreateMaterial(L"SpriteShader", ui_key, L"ui_key_material");

		std::shared_ptr<ya::graphics::Texture> ui_coin
			= Resources::Load<ya::graphics::Texture>(L"ui_coin", L"..\\Resources\\Texture\\UI\\GameUI\\ui_coin.png");
		CreateMaterial(L"SpriteShader", ui_coin, L"ui_coin_material");
				
		std::shared_ptr<ya::graphics::Texture> ui_blank
			= Resources::Load<ya::graphics::Texture>(L"ui_blank", L"..\\Resources\\Texture\\UI\\GameUI\\ui_blank.png");
		CreateMaterial(L"SpriteShader", ui_blank, L"ui_blank_material");

		std::shared_ptr<ya::graphics::Texture> weapon_box_01
			= Resources::Load<ya::graphics::Texture>(L"weapon_box_01", L"..\\Resources\\Texture\\UI\\GameUI\\weapon_box_01.png");
		CreateMaterial(L"SpriteShader", weapon_box_01, L"weapon_box_01_material");

		std::shared_ptr<ya::graphics::Texture> weapon_box_02
			= Resources::Load<ya::graphics::Texture>(L"weapon_box_01", L"..\\Resources\\Texture\\UI\\GameUI\\weapon_box_02.png");
		CreateMaterial(L"SpriteShader", weapon_box_02, L"weapon_box_02_material");

		std::shared_ptr<ya::graphics::Texture> Bullet_count_bottom
			= Resources::Load<ya::graphics::Texture>(L"Bullet_count_bottom", L"..\\Resources\\Texture\\UI\\GameUI\\bullet_count\\Bullet_count_bottom.png");
		CreateMaterial(L"SpriteShader", Bullet_count_bottom, L"Bullet_count_bottom_material");
		
		std::shared_ptr<ya::graphics::Texture> Bullet_count_top
			= Resources::Load<ya::graphics::Texture>(L"Bullet_count_top", L"..\\Resources\\Texture\\UI\\GameUI\\bullet_count\\Bullet_count_top.png");
		CreateMaterial(L"SpriteShader", Bullet_count_top, L"Bullet_count_top_material");


		//bullet emepty
		std::shared_ptr<ya::graphics::Texture> Emepty_Bullet_01
			= Resources::Load<ya::graphics::Texture>(L"Emepty_Bullet_01", L"..\\Resources\\Texture\\UI\\GameUI\\bullet_count\\Emepty\\Emepty_Bullet_01.png");
		CreateMaterial(L"SpriteShader", Emepty_Bullet_01, L"Emepty_Bullet_01_material");


		//bullet type
		std::shared_ptr<ya::graphics::Texture> Bullet_type_01
			= Resources::Load<ya::graphics::Texture>(L"Bullet_type_01", L"..\\Resources\\Texture\\UI\\GameUI\\bullet_count\\Bullet\\Bullet_type_01.png");
		CreateMaterial(L"SpriteShader", Bullet_type_01, L"Bullet_type_01_material");
		


		
	
		

	}

}