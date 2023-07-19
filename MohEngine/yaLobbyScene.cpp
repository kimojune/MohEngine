#include "yaLobbyScene.h"
#include "yaPlayer.h"
#include "yaDog.h"
#include "yaObject.h"

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