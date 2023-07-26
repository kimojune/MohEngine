#include "yaUICamera.h"
#include "yaCamera.h"
#include "yaSceneManager.h"

namespace ya
{
	UICamera::UICamera()
		:mPos(Vector3(0.0f,0.0f,-20.0f))
	{
		SetName(L"UICamera");

		Camera* camera = AddComponent<Camera>();
		camera->SetSize(1.0);
		camera->DisableLayerMasks();
		camera->TurnLayerMask(eLayerType::UI);
		camera->SetCameraType(enums::eCameraType::UI);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);
	}
	UICamera::~UICamera()
	{
	}
	void UICamera::Initialize()
	{
		GameObject::Initialize();
	}
	void UICamera::Update()
	{
		GameObject::Update();
	}
	void UICamera::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void UICamera::Render()
	{
		GameObject::Render();
	}
}