#include "yaChamber1Scene.h"
#include "yaBackGround.h"
#include "yaTilePalatte.h"
#include "yaInput.h"

namespace ya
{
	Chamber1Scene::Chamber1Scene()
	{
		SetName(L"Chamber1");
	}
	Chamber1Scene::~Chamber1Scene()
	{
	}
	void Chamber1Scene::Initialize()
	{
		BackGround* battle_floor_dark_blue_circle_002 = new BackGround(L"battle_floor_dark_blue_circle_002_material");
		battle_floor_dark_blue_circle_002->SetPosition(Vector3(8.0f, 8.0f, 1.0f));

		BackGround* shrine_legend_base_001 = new BackGround(L"shrine_legend_base_001_material");
		shrine_legend_base_001->SetPosition(Vector3(8.0f, 116.0f, 1.0f));

		BackGround* shrine_legend_base_shadow_001 = new BackGround(shrine_legend_base_001, L"shrine_legend_base_shadow_001_material");
		shrine_legend_base_shadow_001->SetPosition(Vector3(0.0f, -48.0f, 1.0f));
		
		BackGround* shrine_legend_statue_001 = new BackGround(shrine_legend_base_001, L"shrine_legend_statue_001_material");
		shrine_legend_statue_001->SetPosition(Vector3(0.0f, 0.0f, 1.0f));

		OnEnter();

		PlayScene::Initialize();

		PlayScene::OnEnter();
	}
	void Chamber1Scene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::L))
		{
			TilePalatte::Clear();
			TilePalatte::Load();
		}


		PlayScene::Update();
	}
	void Chamber1Scene::LateUpdate()
	{
		PlayScene::LateUpdate();
	}
	void Chamber1Scene::Render()
	{
		PlayScene::Render();
	}
	void Chamber1Scene::OnEnter()
	{
		const std::wstring& path = L"..\\Resources\\Tile\\test";
		TilePalatte::Load(path);

		PlayScene::OnEnter();

	}
	void Chamber1Scene::OnExit()
	{
		PlayScene::OnExit();
	}
}