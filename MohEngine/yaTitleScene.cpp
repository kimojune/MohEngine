#include "yaTitleScene.h"
#include "yaPlayer.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaCameraScript.h"
#include "yaApplication.h"
#include "yaInput.h"
#include "yaSceneManager.h"

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

		GameObject* cloud_1 = new GameObject();
		AddGameObject(eLayerType::BG, cloud_1);
		MeshRenderer* cl1mr = cloud_1->AddComponent<MeshRenderer>();
		cl1mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		cl1mr->SetMaterial(Resources::Find<Material>((L"cheapo_cloud_001_material")));
		Transform* cl1tr = cloud_1->GetComponent<Transform>();
		cl1tr->SetPosition(Vector3(0.0f, -half_height / 16, 0.0f));
		cl1tr->SetScale(Vector3(960.0f, 507.0f, 1.0f));

		GameObject* cloud_2 = new GameObject();
		AddGameObject(eLayerType::BG, cloud_2);
		MeshRenderer* cl2mr = cloud_2->AddComponent<MeshRenderer>();
		cl2mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		cl2mr->SetMaterial(Resources::Find<Material>((L"cheapo_cloud_002_material")));
		Transform* cl2tr = cloud_2->GetComponent<Transform>();
		cl2tr->SetPosition(Vector3(0.0f, -half_height / 4, 0.0f));
		cl2tr->SetScale(Vector3(960.0f, 362.f, 1.0f));
		
		GameObject* water = new GameObject();
		AddGameObject(eLayerType::BG, water);
		MeshRenderer* watermr = water->AddComponent<MeshRenderer>();
		watermr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		watermr->SetMaterial(Resources::Find<Material>(L"title_water_001_material"));
		Transform* watertr = water->GetComponent<Transform>();
		watertr->SetPosition(Vector3(0.0f, -half_height / 2, 0.0f));
		watertr->SetScale(Vector3(960.0f, 138.f, 1.0f));

		GameObject* grass = new GameObject();
		AddGameObject(eLayerType::BG, grass);
		MeshRenderer* grassmr = grass->AddComponent<MeshRenderer>();
		grassmr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		grassmr->SetMaterial(Resources::Find<Material>(L"flag_wave_001_material"));
		Transform* grasstr = grass->GetComponent<Transform>();
		grasstr->SetPosition(Vector3(half_width /8 , (-half_height / 2) + (half_height / 16), 0.0f));
		grasstr->SetScale(Vector3(319.0f, 105.0f, 1.0f));



		GameObject* castle = new GameObject();
		AddGameObject(eLayerType::BG, castle);
		MeshRenderer* castlemr = castle->AddComponent<MeshRenderer>();
		castlemr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		castlemr->SetMaterial(Resources::Find<Material>((L"marsh_of_gungeon_material")));
		Transform* castletr = castle->GetComponent<Transform>();
		castletr->SetPosition(Vector3((half_width / 2) - (half_width / 32), -half_height / 8, 0.0f));
		//tr->SetScale(Vector3(296.0f, 437.0f, 1.0f));
		castletr->SetScale(Vector3(296.0f, 437.0f, 1.0f));

		GameObject* dragon = new GameObject();
		AddGameObject(eLayerType::BG, dragon);
		MeshRenderer* dragonmr = dragon->AddComponent<MeshRenderer>();
		dragonmr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		dragonmr->SetMaterial(Resources::Find<Material>((L"dragun_title_screen_001_material")));
		Transform* dragontr = dragon->GetComponent<Transform>();
		dragontr->SetPosition(Vector3((half_width / 2) - (half_width / 12), half_width / 16, 0.0f));
		dragontr->SetScale(Vector3(66.0f, 70.0f, 1.0f));

		GameObject* catlelight = new GameObject();
		AddGameObject(eLayerType::BG, catlelight);
		MeshRenderer* catlelightmr = catlelight->AddComponent<MeshRenderer>();
		catlelightmr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		catlelightmr->SetMaterial(Resources::Find<Material>(L"marsh_of_gungeon_glow_001_material"));
		Transform* catlelighttr = catlelight->GetComponent<Transform>();
		catlelighttr->SetPosition(Vector3((half_width / 2)  - (half_width / 12) + 2.0f, -half_height / 8 + 5.5f, 0.0f));
		catlelighttr->SetScale(Vector3(68.0f, 114.f, 1.0f));

		GameObject* gunmanbot = new GameObject();
		AddGameObject(eLayerType::BG, gunmanbot);
		MeshRenderer* gunmanbotmr = gunmanbot->AddComponent<MeshRenderer>();
		gunmanbotmr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		gunmanbotmr->SetMaterial(Resources::Find<Material>((L"silhouette_lich_bot_material")));
		Transform* gunmanbottr = gunmanbot->GetComponent<Transform>();
		gunmanbottr->SetPosition(Vector3(-half_width/2, -half_height / 3, 0.0f));
		gunmanbottr->SetScale(Vector3(195.0f, 277.0f, 1.0f));

		GameObject* gunmantop = new GameObject();
		AddGameObject(eLayerType::BG, gunmantop);
		MeshRenderer* gunmantopmr = gunmantop->AddComponent<MeshRenderer>();
		gunmantopmr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		gunmantopmr->SetMaterial(Resources::Find<Material>((L"silhouette_lich_top_windy_material")));
		Transform* gunmantoptr = gunmantop->GetComponent<Transform>();
		gunmantoptr->SetPosition(Vector3(-half_width/2 + (half_width / 50), half_height / 4, 0.0f));
		gunmantoptr->SetScale(Vector3(196.0f, 285.0f, 1.0f));

		GameObject* gunmanarm = new GameObject();
		AddGameObject(eLayerType::BG, gunmanarm);
		MeshRenderer* gunmanarmmr = gunmanarm->AddComponent<MeshRenderer>();
		gunmanarmmr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		gunmanarmmr->SetMaterial(Resources::Find<Material>((L"silhouette_lich_click_Material")));
		Transform* gunmanarmtr = gunmanarm->GetComponent<Transform>();
		gunmanarmtr->SetPosition(Vector3((-half_width / 2) + (half_width / 12), half_height / 4, 0.0f));
		gunmanarmtr->SetScale(Vector3(121.0f, 319.0f, 1.0f));
		
		GameObject* title = new GameObject();
		AddGameObject(eLayerType::BG, title);
		MeshRenderer* titlemr = title->AddComponent<MeshRenderer>();
		titlemr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		titlemr->SetMaterial(Resources::Find<Material>((L"title_words_black_001_material")));
		Transform* titletr = title->GetComponent<Transform>();
		titletr->SetPosition(Vector3(0.0f, half_width / 32, 0.0f));
		titletr->SetScale(Vector3(436.0f, 139.0f, 1.0f));
				
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		Camera* camecomp = camera->AddComponent<Camera>();
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		CameraScript* camerasc = camera->AddComponent<CameraScript>();


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