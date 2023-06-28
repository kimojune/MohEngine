#include "yaTitleScene.h"
#include "yaPlayer.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaTransform.h"
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

		Player* player = new Player();
		player->Intialize();
		AddGameObject(eLayerType::Player, player);

		GameObject* obj = new GameObject();
		AddGameObject(eLayerType::UI, obj);
		MeshRenderer* mr = obj->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		mr->SetMaterial(Resources::Find<Material>((L"SpriteMaterial03")));
		Transform* tr = obj->GetComponent<Transform>();
		tr->SetPosition(Vector3(0.5f, 0.5f, -0.4f));
		

	}
	void TitleScene::Update()
	{
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