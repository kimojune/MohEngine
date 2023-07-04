#include "yaPlayScene.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaPlayer.h"
#include "yaPlayerScript.h"
#include "yaMainCamera.h"
#include "hoCursor.h"
#include "yaUICamera.h"

using namespace ho;

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


		//GameObject* dog = new GameObject();
		//AddGameObject(eLayerType::Player, dog);
		//MeshRenderer* mr = dog->AddComponent<MeshRenderer>();
		//mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		//mr->SetMaterial(Resources::Find<Material>((L"dog_idle_left_001")));
		////player->AddComponent<CameraScript>();
		//Transform* dogtr = dog->GetComponent<Transform>();
		//dogtr->SetPosition(Vector3(2.0f, 0.0f, 0.0f));
		//
		

		//GameObject* HP_effect = new GameObject();
		//MeshRenderer* HP_effectmr = HP_effect->AddComponent< MeshRenderer>();
		//HP_effectmr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		//HP_effectmr->SetMaterial(Resources::Find<Material>((L"HP_effect_material")));
		//Transform* HP_effectTr = HP_effect->GetComponent<Transform>();
		//HP_effectTr->SetPosition(Vector3::Zero);
		//HP_effectTr->SetScale(Vector3(100.0f, 14.0f, 0.0f));
		//AddGameObject(eLayerType::UI, HP_effect);


		MainCamera* camera = new MainCamera();
		camera->Intialize();
		UICamera* uicamera = new UICamera();

		Cursor* cursor = new Cursor(uicamera);

		
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