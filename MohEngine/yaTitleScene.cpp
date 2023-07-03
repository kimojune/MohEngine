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

extern ya::Application application;

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

		BackGround* cloud_1 = new BackGround(Vector3(0.0f, -half_height / 16, 0.0f), Vector3(960.0f, 507.0f, 1.0f));
		cloud_1->SetMaterial(L"cheapo_cloud_001_material");
		cloud_1->Intialize();

		BackGround* cloud_2 = new BackGround(Vector3(0.0f, -half_height / 4, 0.0f), Vector3(960.0f, 362.f, 1.0f));
		cloud_2->SetMaterial(L"cheapo_cloud_002_material");
		cloud_2->Intialize();

		BackGround* water = new BackGround(Vector3(0.0f, -half_height / 2, 0.0f), Vector3(960.0f, 138.f, 1.0f));
		water->SetMaterial(L"title_water_001_material");
		water->Intialize();

		BackGround* grass = new BackGround(Vector3(half_width / 8, (-half_height / 2) + (half_height / 16), 0.0f), Vector3(319.0f, 105.0f, 1.0f));
		grass->SetMaterial(L"flag_wave_001_material");
		grass->Intialize();

		BackGround* castle = new BackGround(Vector3((half_width / 2) - (half_width / 32), -half_height / 8, 0.0f), Vector3(296.0f, 437.0f, 1.0f));
		castle->SetMaterial(L"marsh_of_gungeon_material");
		castle->Intialize();
		
		BackGround* dragon = new BackGround(Vector3((half_width / 2) - (half_width / 12), half_width / 16, 0.0f), Vector3(66.0f, 70.0f, 1.0f));
		dragon->SetMaterial(L"dragun_title_screen_001_material");
		dragon->Intialize();

		BackGround* catlelight = new BackGround(Vector3((half_width / 2) - (half_width / 12) + 2.0f, -half_height / 8 + 5.5f, 0.0f), Vector3(68.0f, 114.f, 1.0f));
		catlelight->SetMaterial(L"marsh_of_gungeon_glow_001_material");
		catlelight->Intialize();
		
		BackGround* gunmanbot = new BackGround(Vector3(-half_width / 2, -half_height / 3, 0.0f), Vector3(195.0f, 277.0f, 1.0f));
		gunmanbot->SetMaterial(L"silhouette_lich_bot_material");
		gunmanbot->Intialize();
		
		BackGround* gunmantop = new BackGround(Vector3(-half_width / 2 + (half_width / 50), half_height / 4, 0.0f), Vector3(196.0f, 285.0f, 1.0f));
		gunmantop->SetMaterial(L"silhouette_lich_top_windy_material");
		gunmantop->Intialize();
			
		BackGround* gunmanarm = new BackGround(Vector3((-half_width / 2) + (half_width / 12), half_height / 4, 0.0f), Vector3(121.0f, 319.0f, 1.0f));
		gunmanarm->SetMaterial(L"silhouette_lich_click_Material");
		gunmanarm->Intialize();
					
		BackGround* title = new BackGround(Vector3(0.0f, half_width / 32, 0.0f), Vector3(436.0f, 139.0f, 1.0f));
		title->SetMaterial(L"title_words_black_001_material");
		title->Intialize();

		MainCamera* mainCamera = new MainCamera();
		mainCamera->Intialize();

		//GameObject* mouse = new GameObject();
		//AddGameObject(eLayerType::UI, mouse);
		//Transform* mousetr = mouse->GetComponent<Transform>();
		

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
			
			//if ((mousePos.x >= -218.0f && mousePos.x <= 218.0f)
			//	&& (mousePos.y <= half_width - 64.0f && mousePos.y >= half_width + 64.0f))
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