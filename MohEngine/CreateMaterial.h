#pragma once
#include "..\Engine_SOURCE\yaResources.h"
#include "..\Engine_SOURCE\yaTexture.h"
#include "..\Engine_SOURCE\yaMaterial.h"
#include "..\Engine_SOURCE\yaShader.h"


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

#pragma region TitleScene
		// TitleScene Texture


		std::shared_ptr<ya::graphics::Texture> marsh_of_gungeon_001
			= Resources::Load<ya::graphics::Texture>(L"marsh_of_gungeon_001", L"..\\Resources\\Texture\\TitleScreenCollection\\marsh_of_gungeon_001.png");

		CreateMaterial(L"SpriteShader", marsh_of_gungeon_001, L"marsh_of_gungeon_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> silhouette_lich_bot_idle_001
			= Resources::Load<ya::graphics::Texture>(L"silhouette_lich_bot_idle_001", L"..\\Resources\\Texture\\TitleScreenCollection\\silhouette_lich_bot_idle_001.png");

		CreateMaterial(L"SpriteShader", silhouette_lich_bot_idle_001, L"silhouette_lich_bot_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> silhouette_lich_top_windy_001
			= Resources::Load<ya::graphics::Texture>(L"silhouette_lich_top_windy_001", L"..\\Resources\\Texture\\TitleScreenCollection\\silhouette_lich_top_windy_001.png");
		CreateMaterial(L"SpriteShader", silhouette_lich_top_windy_001, L"silhouette_lich_top_windy_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> cheapo_cloud_001
			= Resources::Load<ya::graphics::Texture>(L"cheapo_cloud_001", L"..\\Resources\\Texture\\TitleScreenCollection\\cheapo_cloud_001.png");
		CreateMaterial(L"SpriteShader", cheapo_cloud_001, L"cheapo_cloud_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> cheapo_cloud_002
			= Resources::Load<ya::graphics::Texture>(L"cheapo_cloud_002", L"..\\Resources\\Texture\\TitleScreenCollection\\cheapo_cloud_002.png");
		CreateMaterial(L"SpriteShader", cheapo_cloud_002, L"cheapo_cloud_002_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> silhouette_lich_click_001
			= Resources::Load<ya::graphics::Texture>(L"silhouette_lich_click_001", L"..\\Resources\\Texture\\TitleScreenCollection\\silhouette_lich_click_001.png");
		CreateMaterial(L"SpriteShader", silhouette_lich_click_001, L"silhouette_lich_click_Material", eRenderingMode::CutOut);
		

		std::shared_ptr<ya::graphics::Texture> title_water_001
			= Resources::Load<ya::graphics::Texture>(L"title_water_001", L"..\\Resources\\Texture\\TitleScreenCollection\\title_water_001.png");
		CreateMaterial(L"SpriteShader", title_water_001, L"title_water_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> marsh_of_gungeon_glow_001
			= Resources::Load<ya::graphics::Texture>(L"marsh_of_gungeon_glow_001", L"..\\Resources\\Texture\\TitleScreenCollection\\marsh_of_gungeon_glow_001.png");
		CreateMaterial(L"SpriteShader", marsh_of_gungeon_glow_001, L"marsh_of_gungeon_glow_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> flag_wave_001
			= Resources::Load<ya::graphics::Texture>(L"flag_wave_001", L"..\\Resources\\Texture\\TitleScreenCollection\\flag_wave_001.png");
		CreateMaterial(L"SpriteShader", flag_wave_001, L"flag_wave_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> title_words_black_001
			= Resources::Load<ya::graphics::Texture>(L"title_words_black_001", L"..\\Resources\\Texture\\TitleScreenCollection\\title_words_black_001.png");
		CreateMaterial(L"SpriteShader", title_words_black_001, L"title_words_black_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> dragun_title_screen_001
			= Resources::Load<ya::graphics::Texture>(L"dragun_title_screen_001", L"..\\Resources\\Texture\\TitleScreenCollection\\dragun_title_screen_001.png");
		CreateMaterial(L"SpriteShader", dragun_title_screen_001, L"dragun_title_screen_001_material", eRenderingMode::CutOut);
#pragma endregion
		
#pragma region UI
		std::shared_ptr<ya::graphics::Texture> reticle_crosshair_002
			= Resources::Load<ya::graphics::Texture>(L"reticle_crosshair_002", L"..\\Resources\\Texture\\UI\\reticle_crosshair_002.png");
		CreateMaterial(L"SpriteShader", reticle_crosshair_002, L"reticle_crosshair_002_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> HP_effect
			= Resources::Load<ya::graphics::Texture>(L"HP_effect", L"..\\Resources\\Texture\\UI\\GameUI\\HP_effect.png");
		CreateMaterial(L"SpriteShader", HP_effect, L"HP_effect_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> Heart
			= Resources::Load<ya::graphics::Texture>(L"Heart", L"..\\Resources\\Texture\\UI\\GameUI\\Heart.png");
		CreateMaterial(L"SpriteShader", Heart, L"Heart_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> ui_key
			= Resources::Load<ya::graphics::Texture>(L"ui_key", L"..\\Resources\\Texture\\UI\\GameUI\\ui_key.png");
		CreateMaterial(L"SpriteShader", ui_key, L"ui_key_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> ui_coin
			= Resources::Load<ya::graphics::Texture>(L"ui_coin", L"..\\Resources\\Texture\\UI\\GameUI\\ui_coin.png");
		CreateMaterial(L"SpriteShader", ui_coin, L"ui_coin_material", eRenderingMode::CutOut);
				
		std::shared_ptr<ya::graphics::Texture> ui_blank
			= Resources::Load<ya::graphics::Texture>(L"ui_blank", L"..\\Resources\\Texture\\UI\\GameUI\\ui_blank.png");
		CreateMaterial(L"SpriteShader", ui_blank, L"ui_blank_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> weapon_box_01
			= Resources::Load<ya::graphics::Texture>(L"weapon_box_01", L"..\\Resources\\Texture\\UI\\GameUI\\weapon_box_01.png");
		CreateMaterial(L"SpriteShader", weapon_box_01, L"weapon_box_01_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> weapon_box_02
			= Resources::Load<ya::graphics::Texture>(L"weapon_box_01", L"..\\Resources\\Texture\\UI\\GameUI\\weapon_box_02.png");
		CreateMaterial(L"SpriteShader", weapon_box_02, L"weapon_box_02_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> Bullet_count_bottom
			= Resources::Load<ya::graphics::Texture>(L"Bullet_count_bottom", L"..\\Resources\\Texture\\UI\\GameUI\\bullet_count\\Bullet_count_bottom.png");
		CreateMaterial(L"SpriteShader", Bullet_count_bottom, L"Bullet_count_bottom_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> Bullet_count_top
			= Resources::Load<ya::graphics::Texture>(L"Bullet_count_top", L"..\\Resources\\Texture\\UI\\GameUI\\bullet_count\\Bullet_count_top.png");
		CreateMaterial(L"SpriteShader", Bullet_count_top, L"Bullet_count_top_material", eRenderingMode::CutOut);


		//bullet emepty
		std::shared_ptr<ya::graphics::Texture> Emepty_Bullet_01
			= Resources::Load<ya::graphics::Texture>(L"Emepty_Bullet_01", L"..\\Resources\\Texture\\UI\\GameUI\\bullet_count\\Emepty\\Emepty_Bullet_01.png");
		CreateMaterial(L"SpriteShader", Emepty_Bullet_01, L"Emepty_Bullet_01_material", eRenderingMode::CutOut);


		//bullet type
		std::shared_ptr<ya::graphics::Texture> Bullet_type_01
			= Resources::Load<ya::graphics::Texture>(L"Bullet_type_01", L"..\\Resources\\Texture\\UI\\GameUI\\bullet_count\\Bullet\\Bullet_type_01.png");
		CreateMaterial(L"SpriteShader", Bullet_type_01, L"Bullet_type_01_material", eRenderingMode::CutOut);
#pragma endregion


#pragma region Lobby
		
		std::shared_ptr<ya::graphics::Texture> new_bottom_floor_level_one_final_floor_001
			= Resources::Load<ya::graphics::Texture>(L"new_bottom_floor_level_one_final_floor_001", L"..\\Resources\\Texture\\Foyer_Collection\\new_bottom_floor_level_one_final_floor_001.png");
		CreateMaterial(L"SpriteShader", new_bottom_floor_level_one_final_floor_001, L"new_bottom_floor_level_one_final_floor_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> circle_floor_pitwall_001
			= Resources::Load<ya::graphics::Texture>(L"circle_floor_pitwall_001", L"..\\Resources\\Texture\\Foyer_Collection\\circle_floor_pitwall_001.png");
		CreateMaterial(L"SpriteShader", circle_floor_pitwall_001, L"circle_floor_pitwall_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> bottom_floor_level_two_pitwall_001
			= Resources::Load<ya::graphics::Texture>(L"bottom_floor_level_two_pitwall_001", L"..\\Resources\\Texture\\Foyer_Collection\\bottom_floor_level_two_pitwall_001.png");
		CreateMaterial(L"SpriteShader", bottom_floor_level_two_pitwall_001, L"bottom_floor_level_two_pitwall_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> circle_floor_top_001
			= Resources::Load<ya::graphics::Texture>(L"circle_floor_top_001", L"..\\Resources\\Texture\\Foyer_Collection\\circle_floor_top_001.png");
		CreateMaterial(L"SpriteShader", circle_floor_top_001, L"circle_floor_top_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> main_stairway_001
			= Resources::Load<ya::graphics::Texture>(L"main_stairway_001", L"..\\Resources\\Texture\\Foyer_Collection\\main_stairway_001.png");
		CreateMaterial(L"SpriteShader", main_stairway_001, L"main_stairway_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> bottom_floor_side_stairs_001
			= Resources::Load<ya::graphics::Texture>(L"bottom_floor_side_stairs_001", L"..\\Resources\\Texture\\Foyer_Collection\\bottom_floor_side_stairs_001.png");
		CreateMaterial(L"SpriteShader", bottom_floor_side_stairs_001, L"bottom_floor_side_stairs_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> bottom_floor_level_two_001
			= Resources::Load<ya::graphics::Texture>(L"bottom_floor_level_two_001", L"..\\Resources\\Texture\\Foyer_Collection\\bottom_floor_level_two_001.png");
		CreateMaterial(L"SpriteShader", bottom_floor_level_two_001, L"bottom_floor_level_two_001_material", eRenderingMode::CutOut);
	
		std::shared_ptr<ya::graphics::Texture> before_into_stage_001
			= Resources::Load<ya::graphics::Texture>(L"before_into_stage_001", L"..\\Resources\\Texture\\Foyer_Collection\\before_into_stage_001.png");
		CreateMaterial(L"SpriteShader", before_into_stage_001, L"before_into_stage_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> foyer_new_entrance_archway_topwalls_001
			= Resources::Load<ya::graphics::Texture>(L"foyer_new_entrance_archway_topwalls_001", L"..\\Resources\\Texture\\Foyer_Collection\\foyer_new_entrance_archway_topwalls_001.png");
		CreateMaterial(L"SpriteShader", foyer_new_entrance_archway_topwalls_001, L"foyer_new_entrance_archway_topwalls_001_material", eRenderingMode::CutOut);
	
		std::shared_ptr<ya::graphics::Texture> bottom_wall_001
			= Resources::Load<ya::graphics::Texture>(L"bottom_wall_001", L"..\\Resources\\Texture\\Foyer_Collection\\bottom_wall_001.png");
		CreateMaterial(L"SpriteShader", bottom_wall_001, L"bottom_wall_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> top_floor_wall_001
			= Resources::Load<ya::graphics::Texture>(L"top_floor_wall_001", L"..\\Resources\\Texture\\Foyer_Collection\\top_floor_wall_001.png");
		CreateMaterial(L"SpriteShader", top_floor_wall_001, L"top_floor_wall_001_material", eRenderingMode::CutOut);
	
		std::shared_ptr<ya::graphics::Texture> new_bottom_wall_001
			= Resources::Load<ya::graphics::Texture>(L"new_bottom_wall_001", L"..\\Resources\\Texture\\Foyer_Collection\\new_bottom_wall_001.png");
		CreateMaterial(L"SpriteShader", new_bottom_wall_001, L"new_bottom_wall_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> new_bottom_wall_002
			= Resources::Load<ya::graphics::Texture>(L"new_bottom_wall_002", L"..\\Resources\\Texture\\Foyer_Collection\\new_bottom_wall_002.png");
		CreateMaterial(L"SpriteShader", new_bottom_wall_002, L"new_bottom_wall_002_material", eRenderingMode::CutOut);


		std::shared_ptr<ya::graphics::Texture> new_pit_border_001
			= Resources::Load<ya::graphics::Texture>(L"new_pit_border_001", L"..\\Resources\\Texture\\Foyer_Collection\\new_pit_border_001.png");
		CreateMaterial(L"SpriteShader", new_pit_border_001, L"new_pit_border_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> pit_border_002
			= Resources::Load<ya::graphics::Texture>(L"pit_border_002", L"..\\Resources\\Texture\\Foyer_Collection\\pit_border_002.png");
		CreateMaterial(L"SpriteShader", pit_border_002, L"pit_border_002_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> pit_border_003
			= Resources::Load<ya::graphics::Texture>(L"pit_border_003", L"..\\Resources\\Texture\\Foyer_Collection\\pit_border_003.png");
		CreateMaterial(L"SpriteShader", pit_border_003, L"pit_border_003_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> new_pit_border_004
			= Resources::Load<ya::graphics::Texture>(L"new_pit_border_004", L"..\\Resources\\Texture\\Foyer_Collection\\new_pit_border_004.png");
		CreateMaterial(L"SpriteShader", new_pit_border_004, L"new_pit_border_004_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> ceiling_borders_black_001
			= Resources::Load<ya::graphics::Texture>(L"ceiling_borders_black_001", L"..\\Resources\\Texture\\Foyer_Collection\\ceiling_borders_black_001.png");
		CreateMaterial(L"SpriteShader", ceiling_borders_black_001, L"ceiling_borders_black_001_material", eRenderingMode::Opaque);

		std::shared_ptr<ya::graphics::Texture> bullet_giant_001
			= Resources::Load<ya::graphics::Texture>(L"bullet_giant_001", L"..\\Resources\\Texture\\Foyer_Collection\\bullet_giant_001.png");
		CreateMaterial(L"SpriteShader", bullet_giant_001, L"bullet_giant_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> bullet_door_001
			= Resources::Load<ya::graphics::Texture>(L"bullet_door_001", L"..\\Resources\\Texture\\Foyer_Collection\\bullet_door_001.png");
		CreateMaterial(L"SpriteShader", bullet_door_001, L"bullet_door_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> archway_upper_001
			= Resources::Load<ya::graphics::Texture>(L"archway_upper_001", L"..\\Resources\\Texture\\Foyer_Collection\\archway_upper_001.png");
		CreateMaterial(L"SpriteShader", archway_upper_001, L"archway_upper_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> livery_boxes_001
			= Resources::Load<ya::graphics::Texture>(L"livery_boxes_001", L"..\\Resources\\Texture\\Foyer_Collection\\livery_boxes_001.png");
		CreateMaterial(L"SpriteShader", livery_boxes_001, L"livery_boxes_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> livery_tent_001
			= Resources::Load<ya::graphics::Texture>(L"livery_tent_001", L"..\\Resources\\Texture\\Foyer_Collection\\livery_tent_001.png");
		CreateMaterial(L"SpriteShader", livery_tent_001, L"livery_tent_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> livery_poker_table_001
			= Resources::Load<ya::graphics::Texture>(L"livery_poker_table_001", L"..\\Resources\\Texture\\Foyer_Collection\\livery_poker_table_001.png");
		CreateMaterial(L"SpriteShader", livery_poker_table_001, L"livery_poker_table_001_material", eRenderingMode::Transparent);
		
		std::shared_ptr<ya::graphics::Texture> livery_bunk_001
			= Resources::Load<ya::graphics::Texture>(L"livery_bunk_001", L"..\\Resources\\Texture\\Foyer_Collection\\livery_bunk_001.png");
		CreateMaterial(L"SpriteShader", livery_bunk_001, L"livery_bunk_001_material", eRenderingMode::Transparent);

		std::shared_ptr<ya::graphics::Texture> livery_couch_001
			= Resources::Load<ya::graphics::Texture>(L"livery_couch_001", L"..\\Resources\\Texture\\Foyer_Collection\\livery_couch_001.png");
		CreateMaterial(L"SpriteShader", livery_couch_001, L"livery_couch_001_material", eRenderingMode::Transparent);
		
		std::shared_ptr<ya::graphics::Texture> livery_easychair_001
			= Resources::Load<ya::graphics::Texture>(L"livery_easychair_001", L"..\\Resources\\Texture\\Foyer_Collection\\livery_easychair_001.png");
		CreateMaterial(L"SpriteShader", livery_easychair_001, L"livery_easychair_001_material", eRenderingMode::Transparent);

		std::shared_ptr<ya::graphics::Texture> elevator_icon_001
			= Resources::Load<ya::graphics::Texture>(L"elevator_icon_001", L"..\\Resources\\Texture\\Foyer_Collection\\elevator_icon_001.png");
		CreateMaterial(L"SpriteShader", elevator_icon_001, L"elevator_icon_001_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> tutorial_icon_001
			= Resources::Load<ya::graphics::Texture>(L"tutorial_icon_001", L"..\\Resources\\Texture\\Foyer_Collection\\tutorial_icon_001.png");
		CreateMaterial(L"SpriteShader", tutorial_icon_001, L"tutorial_icon_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> right_railing_001
			= Resources::Load<ya::graphics::Texture>(L"right_railing_001", L"..\\Resources\\Texture\\Foyer_Collection\\right_railing_001.png");
		CreateMaterial(L"SpriteShader", right_railing_001, L"right_railing_material", eRenderingMode::CutOut);
		
		std::shared_ptr<ya::graphics::Texture> left_railing_001
			= Resources::Load<ya::graphics::Texture>(L"left_railing_001", L"..\\Resources\\Texture\\Foyer_Collection\\left_railing_001.png");
		CreateMaterial(L"SpriteShader", left_railing_001, L"left_railing_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> bullet_collumn_anger_001
			= Resources::Load<ya::graphics::Texture>(L"bullet_collumn_anger_001", L"..\\Resources\\Texture\\Foyer_Collection\\bullet_collumn_anger_001.png");
		CreateMaterial(L"SpriteShader", bullet_collumn_anger_001, L"bullet_collumn_anger_001_material", eRenderingMode::Transparent);

		std::shared_ptr<ya::graphics::Texture> bullet_collumn_dignity_001
			= Resources::Load<ya::graphics::Texture>(L"bullet_collumn_dignity_001", L"..\\Resources\\Texture\\Foyer_Collection\\bullet_collumn_dignity_001.png");
		CreateMaterial(L"SpriteShader", bullet_collumn_dignity_001, L"bullet_collumn_dignity_001_material", eRenderingMode::Transparent);
		
		std::shared_ptr<ya::graphics::Texture> bullet_collumn_horror_001
			= Resources::Load<ya::graphics::Texture>(L"bullet_collumn_horror_001", L"..\\Resources\\Texture\\Foyer_Collection\\bullet_collumn_horror_001.png");
		CreateMaterial(L"SpriteShader", bullet_collumn_horror_001, L"bullet_collumn_horror_001_material", eRenderingMode::Transparent);

		std::shared_ptr<ya::graphics::Texture> bullet_collumn_ignorance_001
			= Resources::Load<ya::graphics::Texture>(L"bullet_collumn_ignorance_001", L"..\\Resources\\Texture\\Foyer_Collection\\bullet_collumn_ignorance_001.png");
		CreateMaterial(L"SpriteShader", bullet_collumn_ignorance_001, L"bullet_collumn_ignorance_001_material", eRenderingMode::Transparent);
		
		

		


#pragma endregion



		std::shared_ptr<ya::graphics::Texture> guide_idle_front_001
			= Resources::Load<ya::graphics::Texture>(L"guide_idle_front_001", L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\front\\guide_idle_front_001.png");
		CreateMaterial(L"SpriteShader", guide_idle_front_001, L"guide_idle_front_001_material", eRenderingMode::CutOut);

		std::shared_ptr<ya::graphics::Texture> dog_idle_left_001
			= Resources::Load<ya::graphics::Texture>(L"dog_idle_left_001", L"..\\Resources\\Texture\\Charactor\\The Hunter\\Companions\\idle_left\\dog_idle_left_001.png");

		CreateMaterial(L"SpriteShader", dog_idle_left_001, L"dog_idle_left_001_material", eRenderingMode::CutOut);

		//Tile Texture
		std::shared_ptr<ya::graphics::Texture> tile
			= Resources::Load<ya::graphics::Texture>(L"Tile", L"..\\Resources\\Tile\\Tile.bmp");
		CreateMaterial(L"TileShader", tile, L"tile_material");
		
	
		

	}

}