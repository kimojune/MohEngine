#include "yaUICamera.h"
#include "yaCamera.h"
#include "yaSceneManager.h"

namespace ya
{
	UICamera::UICamera()
		:mPos(Vector3(0.0f,0.0f,-20.0f))
	{
		Camera* camera = AddComponent<Camera>();
		camera->SetSize(0.3f);
		camera->DisableLayerMasks();
		camera->TurnLayerMask(eLayerType::UI);
		camera->SetType(Camera::eProjectionType::OrthoGraphic);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);

		

		SetName(L"UICamera");

	}
	UICamera::~UICamera()
	{
	}
	void UICamera::Intialize()
	{
		GameObject::Intialize();
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