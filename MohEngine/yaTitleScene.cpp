#include "yaTitleScene.h"
#include "yaPlayer.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaMainCamera.h"
#include "yaApplication.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBackGround.h"
#include "hoCursor.h"

extern ya::Application application;

using namespace ho;

namespace ya
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{

		int width = application.GetWidth();
		int height = application.GetHeight();

		int half_width = width / 2;
		int half_height = height / 2;

		BackGround* cloud_1 = new BackGround(Vector3(0.0f, -half_height / 16, 0.0f), (L"cheapo_cloud_001_material"));
		BackGround* cloud_2 = new BackGround(Vector3(0.0f, -half_height / 4, 0.0f), (L"cheapo_cloud_002_material"));
		BackGround* water = new BackGround(Vector3(0.0f, -half_height / 2, 0.0f), (L"title_water_001_material"));
		BackGround* grass = new BackGround(Vector3(half_width / 8, (-half_height / 2) + (half_height / 16), 0.0f), (L"flag_wave_001_material"));
		BackGround* castle = new BackGround(Vector3((half_width / 2) - (half_width / 32), -half_height / 8, 0.0f), (L"marsh_of_gungeon_material"));
		BackGround* dragon = new BackGround(Vector3((half_width / 2) - (half_width / 12), half_width / 16, 0.0f), (L"dragun_title_screen_001_material"));
		BackGround* catlelight = new BackGround(Vector3((half_width / 2) - (half_width / 12) + 2.0f, -half_height / 8 + 5.5f, 0.0f), (L"marsh_of_gungeon_glow_001_material"));
		BackGround* gunmanbot = new BackGround(Vector3(-half_width / 2, -half_height / 3, 0.0f), (L"silhouette_lich_bot_material"));
		BackGround* gunmantop = new BackGround(Vector3(-half_width / 2 + (half_width / 50), half_height / 4, 0.0f), (L"silhouette_lich_top_windy_material"));
		BackGround* gunmanarm = new BackGround(Vector3((-half_width / 2) + (half_width / 12), half_height / 4, 0.0f), (L"silhouette_lich_click_Material"));
		BackGround* title = new BackGround(Vector3(0.0f, half_width / 32, 0.0f), (L"title_words_black_001_material"));

		MainCamera* mainCamera = new MainCamera();
		UICamera* uicamera = new UICamera();

		Cursor* cursor = new Cursor(uicamera);
	}
	void TitleScene::Update()
	{
		int width = application.GetWidth();
		int height = application.GetHeight();

		int half_width = width / 2;
		int half_height = height / 2;

		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			Vector2 mousePos = Input::GetMousePos();	
			SceneManager::LoadScene(L"PlayScene");
		}

		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void TitleScene::Render()
	{
		Scene::Render();
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}