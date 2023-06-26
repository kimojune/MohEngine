#include "yaPlayScene.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaCameraScript.h"
#include "yaCamera.h"
#include "yaPlayer.h"

namespace ya
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		{
		Player* player = new Player();
		player->Intialize();
		AddGameObject(eLayerType::Player, player);
		Camera* cameraComp = player->AddComponent<Camera>();
		player->AddComponent<CameraScript>();
		}

		{
		GameObject* player = new GameObject();
		AddGameObject(eLayerType::Player, player);
		MeshRenderer* mr = player->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		mr->SetMaterial(Resources::Find<Material>((L"SpriteMaterial02")));
		//player->AddComponent<CameraScript>();
		Transform* tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector3(2.0f, 0.0f, 0.0f));
		}

		//GameObject* camera = new GameObject();
		//AddGameObject(eLayerType::Player, camera);
		//camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		//camera->AddComponent<CameraScript>();

	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render()
	{
		Scene::Render();
	}
}