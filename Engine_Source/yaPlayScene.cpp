#include "yaPlayScene.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaCameraScript.h"
#include "yaCamera.h"
#include "yaPlayer.h"
#include "yaPlayerScript.h"

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
		
		Player* player = new Player();
		player->Intialize();
		AddGameObject(eLayerType::Player, player);
		player->AddComponent<PlayerScript>();
		
		GameObject* dog = new GameObject();
		AddGameObject(eLayerType::Companions, dog);
		MeshRenderer* mr = dog->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		mr->SetMaterial(Resources::Find<Material>((L"SpriteMaterial02")));
		//player->AddComponent<CameraScript>();
		Transform* dogtr = dog->GetComponent<Transform>();
		dogtr->SetPosition(Vector3(2.0f, 0.0f, 0.0f));
		
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		Camera* camecomp = camera->AddComponent<Camera>();
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		CameraScript* camerasc = camera->AddComponent<CameraScript>();
		camerasc->SetTarget(player);
		
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