#include "yaLobbyScene.h"
#include "yaPlayer.h"
#include "yaDog.h"
#include "yaObject.h"
#include "yaBackGround.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaMeshRenderer.h"
namespace ya
{
	LobbyScene::LobbyScene()
	{
	}
	LobbyScene::~LobbyScene()
	{
	}
	void LobbyScene::Initialize()
	{
#pragma region BackGround

		BackGround* circle_floor_pitwall_001 = new BackGround(L"circle_floor_pitwall_001_material");
		circle_floor_pitwall_001->SetPosition(Vector3(0.0f, 100.0f, 1.0f));

		BackGround* bottom_floor_level_two_pitwall_001 = new BackGround(L"bottom_floor_level_two_pitwall_001_material");
		bottom_floor_level_two_pitwall_001->SetPosition(Vector3(0.0f, 125.0f, 1.0f));

		BackGround* new_pit_border_001 = new BackGround(L"new_pit_border_001_material");
		new_pit_border_001->SetPosition(Vector3(-329.0f, 110.0f, 1.0f));

		BackGround* pit_border_002 = new BackGround(L"pit_border_002_material");
		pit_border_002->SetPosition(Vector3(-108.0f, 105.0f, 1.0f));

		BackGround* pit_border_003 = new BackGround(L"pit_border_003_material");
		pit_border_003->SetPosition(Vector3(108.0f, 105.0f, 1.0f));

		BackGround* new_pit_border_004 = new BackGround(L"new_pit_border_004_material");
		new_pit_border_004->SetPosition(Vector3(329.0f, 110.0f, 1.0f));

		BackGround* ceiling_borders_black_001 = new BackGround(L"ceiling_borders_black_001_material");
		ceiling_borders_black_001->SetPosition(Vector3(0.0f, -140.0f, 1.0f));

		BackGround* mainFloor = new BackGround(L"new_bottom_floor_level_one_final_floor_001_material");
		mainFloor->SetPosition(Vector3(0.0f, 0.0f, 1.0f));

		BackGround* circle_floor_top_001 = new BackGround(L"circle_floor_top_001_material");
		circle_floor_top_001->SetPosition(Vector3(0.0f, 125.0f, 1.0f));

		BackGround* main_stairway_001 = new BackGround(L"main_stairway_001_material");
		main_stairway_001->SetPosition(Vector3(0.0f, 332.0f, 1.0f));

		BackGround* bottom_floor_level_two_001 = new BackGround(L"bottom_floor_level_two_001_material");
		bottom_floor_level_two_001->SetPosition(Vector3(0.0f, 222.0f, 1.0f));

		BackGround* before_into_stage_001 = new BackGround(L"before_into_stage_001_material");
		before_into_stage_001->SetPosition(Vector3(0.0f, 582.0f, 1.0f));

		BackGround* bottom_floor_side_stairs_left = new BackGround(L"bottom_floor_side_stairs_001_material");
		bottom_floor_side_stairs_left->SetPosition(Vector3(-208.0f, 170.0f, 1.0f));

		BackGround* bottom_floor_side_stairs_right = new BackGround(L"bottom_floor_side_stairs_001_material");
		bottom_floor_side_stairs_right->SetPosition(Vector3(208.0f, 170.0f, 1.0f));

		BackGround* foyer_new_entrance_archway_topwalls_001 = new BackGround(mainFloor, L"foyer_new_entrance_archway_topwalls_001_material");
		foyer_new_entrance_archway_topwalls_001->SetPosition(Vector3(0.0f, 350.0f, 1.5f));

		BackGround* bottom_wall_001 = new BackGround(L"bottom_wall_001_material");
		bottom_wall_001->SetPosition(Vector3(0.0f, 380.0f, 1.0f));

		BackGround* top_floor_wall_001 = new BackGround(L"top_floor_wall_001_material");
		top_floor_wall_001->SetPosition(Vector3(0.0f, 764.0f, 1.0f));

		BackGround* new_bottom_wall_001 = new BackGround(L"new_bottom_wall_001_material");
		new_bottom_wall_001->SetPosition(Vector3(-408.0f, 175.0f, 1.0f));

		BackGround* new_bottom_wall_002 = new BackGround(L"new_bottom_wall_002_material");
		new_bottom_wall_002->SetPosition(Vector3(408.0f, 175.0f, 1.0f));

		BackGround* bullet_giant_001 = new BackGround(L"bullet_giant_001_material");
		bullet_giant_001->SetPosition(Vector3(0.0f, 750.0f, 1.0f));

		BackGround* bullet_door_001 = new BackGround(L"bullet_door_001_material");
		bullet_door_001->SetPosition(Vector3(0.0f, 600.0f, 1.0f));

		BackGround* archway_upper_001 = new BackGround(L"archway_upper_001_material");
		archway_upper_001->SetPosition(Vector3(-175.0f, 725.0f, 1.0f));

		BackGround* archway_upper_002 = new BackGround(L"archway_upper_001_material");
		archway_upper_002->SetPosition(Vector3(-208.0f, 308.0f, 1.0f));

		BackGround* archway_upper_003 = new BackGround(L"archway_upper_001_material");
		archway_upper_003->SetPosition(Vector3(260.0f, 308.0f, 1.0f));

		BackGround* livery_boxes_001 = new BackGround(L"livery_boxes_001_material");
		livery_boxes_001->SetPosition(Vector3(-388.0f, -60.0f, 1.0f));

		BackGround* livery_tent_001 = new BackGround(livery_boxes_001, L"livery_tent_001_material");
		livery_tent_001->SetPosition(Vector3(50.0f, 50.0f, 1.0f));

		BackGround* livery_bunk_001 = new BackGround(livery_boxes_001, L"livery_bunk_001_material");
		livery_bunk_001->SetPosition(Vector3(13.0f, 138.0f, 1.0f));

		BackGround* livery_poker_table_001 = new BackGround(livery_boxes_001, L"livery_poker_table_001_material");
		livery_poker_table_001->SetPosition(Vector3(200.0f, 50.0f, 1.0f));

		BackGround* livery_couch_001 = new BackGround(livery_poker_table_001, L"livery_couch_001_material");
		livery_couch_001->SetPosition(Vector3(-50.0f, -38.0f, 1.0f));

		BackGround* livery_easychair_001 = new BackGround(livery_poker_table_001, L"livery_easychair_001_material");
		livery_easychair_001->SetPosition(Vector3(38.0f, -38.0f, 1.0f));

		BackGround* elevator_icon_001 = new BackGround(archway_upper_003, L"elevator_icon_001_material");
		elevator_icon_001->SetPosition(Vector3(0.0f, 38.0f, 1.0f));

		BackGround* tutorial_icon_001 = new BackGround(archway_upper_002, L"tutorial_icon_001_material");
		tutorial_icon_001->SetPosition(Vector3(0.0f, 40.0f, 1.0f));


		BackGround* left_railing_001 = new BackGround(archway_upper_002, L"left_railing_material");
		left_railing_001->SetPosition(Vector3(24.0f, 166.0f, 1.0f));

		BackGround* right_railing_001 = new BackGround(left_railing_001, L"right_railing_material");
		right_railing_001->SetPosition(Vector3(368.0f, 0.0f, 1.0f));


		BackGround* bullet_collumn_anger_001 = new BackGround(archway_upper_001, L"bullet_collumn_anger_001_material");
		bullet_collumn_anger_001->SetPosition(Vector3(-40.0f, 50.0f, 1.0f));

		BackGround* bullet_collumn_dignity_001 = new BackGround(bullet_collumn_anger_001, L"bullet_collumn_dignity_001_material");
		bullet_collumn_dignity_001->SetPosition(Vector3(88.0f, 0.0f, 1.0f));

		BackGround* bullet_collumn_horror_001 = new BackGround(bullet_collumn_dignity_001, L"bullet_collumn_horror_001_material");
		bullet_collumn_horror_001->SetPosition(Vector3(260.0f, 0.0f, 1.0f));

		BackGround* bullet_collumn_ignorance_001 = new BackGround(bullet_collumn_horror_001, L"bullet_collumn_ignorance_001_material");
		bullet_collumn_ignorance_001->SetPosition(Vector3(88.0f, 0.0f, 1.0f));
#pragma endregion

		Dog* dog = object::Instantiate<Dog>(eLayerType::Companions);
		Collider2D* dogcd = dog->AddComponent<Collider2D>();
		Transform* tr = dog->GetComponent<Transform>();
		float degree = PI / 8.0f;
		tr->SetRotation(Vector3(0.0f, 0.0f, degree));
		dogcd->SetCenter(Vector2(0.0f, 0.0f));
		dogcd->SetType(eColliderType::Rect);

		PlayScene::Initialize();
	}
	void LobbyScene::Update()
	{
		PlayScene::Update();
	}
	void LobbyScene::LateUpdate()
	{
		PlayScene::LateUpdate();
	}
	void LobbyScene::Render()
	{
		PlayScene::Render();
	}
	void LobbyScene::OnEnter()
	{
		
		PlayScene::OnEnter();
	}
	void LobbyScene::OnExit()
	{
		PlayScene::OnExit();
	}
}