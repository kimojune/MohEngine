#include "yaMainCamera.h"
#include "yaCamera.h"
#include "yaSceneManager.h"
#include "yaCameraScript.h"

namespace ya
{
	MainCamera::MainCamera()
		:mPos(Vector3(0.0f, 0.0f, -10.0f))
	{
	}
	MainCamera::~MainCamera()
	{
	}
	void MainCamera::Intialize()
	{
		Camera* camera =AddComponent<Camera>();
		camera->SetSize(0.6f);
	
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);
		AddComponent<CameraScript>();

		GameObject::Intialize();
	}
	void MainCamera::Update()
	{
		GameObject::Update();
	}
	void MainCamera::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void MainCamera::Render()
	{
		GameObject::Render();
	}
}