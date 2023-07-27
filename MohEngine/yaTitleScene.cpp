#include "yaTitleScene.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaMainCamera.h"
#include "yaApplication.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBackGround.h"
#include "yaCursor.h"

extern ya::Application application;

using namespace ya;

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
		MainCamera* mainCamera = new MainCamera();
		UICamera* uicamera = new UICamera();
		mainCamera->SetSize(1.0f);

		float mainCameraSize = mainCamera->GetSize();
		
		BackGround* cloud_1 = new BackGround((L"cheapo_cloud_001_material"));
		cloud_1->SetPosition(Vector3(0.0f, 100.0f, -0.3f));

		BackGround* cloud_2 = new BackGround(cloud_1, (L"cheapo_cloud_002_material"));
		cloud_2->SetPosition(Vector3(0.0f, -150.0f , -0.3f));
		
		BackGround* water = new BackGround(cloud_2, (L"title_water_001_material"));
		water->SetPosition(Vector3(0.0f, -120.0f , -0.3f));

		BackGround* grass = new BackGround(water, (L"flag_wave_001_material"));
		grass->SetPosition(Vector3(0.0f, 0.0f, -0.3f));

		BackGround* castle = new BackGround((L"marsh_of_gungeon_material"));
		castle->SetPosition(Vector3(300.0f , 0.0f, -0.3f));

		BackGround* catlelight = new BackGround(castle, (L"marsh_of_gungeon_glow_001_material"));
		catlelight->SetPosition(Vector3(-38.0f , 5.0f, -0.3f));

		BackGround* dragon = new BackGround(catlelight,(L"dragun_title_screen_001_material"));
		dragon->SetPosition(Vector3(-5.0f, 110.0f, -0.3f));

		BackGround* gunmanbot = new BackGround((L"silhouette_lich_bot_material"));
		gunmanbot->SetPosition(Vector3(-300.0f , -100.0f, -0.3f));

		BackGround* gunmantop = new BackGround(gunmanbot, (L"silhouette_lich_top_windy_material"));
		gunmantop->SetPosition(Vector3(0.0f, 200.0f ,-0.3f));

		BackGround* gunmanarm = new BackGround(gunmanbot, (L"silhouette_lich_click_Material"));
		gunmanarm->SetPosition(Vector3(70.0f, 150.0f, -0.3f));

		BackGround* title = new BackGround((L"title_words_black_001_material"));
		title->SetPosition(Vector3(0.0f, 0.0f, -0.3f));



		Cursor* cursor = new Cursor;
	}
	void TitleScene::Update()
	{
		int width = application.GetWidth();
		int height = application.GetHeight();

		int half_width = width / 2;
		int half_height = height / 2;

		//if (Input::GetKeyDown(eKeyCode::LBUTTON))
		//{
		//	Vector2 mousePos = Input::GetMousePos();	
		//	SceneManager::LoadScene(L"LobbyScene");
		//}

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