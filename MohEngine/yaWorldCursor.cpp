#include "yaWorldCursor.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaSceneManager.h"

namespace ya
{
	WorldCursor::WorldCursor()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector3::One);
		tr->SetPosition(Vector3::Zero);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);
		SetName(L"worldCursor");
	}
	WorldCursor::~WorldCursor()
	{
	}
	void WorldCursor::Initialize()
	{
	}
	void WorldCursor::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 Pos = ya::Input::GetClientMousePos(eCameraType::Main);
		mPos = Vector3(Pos.x, Pos.y, -10.0f);
		
		tr->SetPosition(mPos);

		GameObject::Update();
	}
	void WorldCursor::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void WorldCursor::Render()
	{
		GameObject::Render();
	}

}