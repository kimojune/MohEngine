#include "yaMainCamera.h"
#include "yaCamera.h"
#include "yaSceneManager.h"
#include "yaCameraScript.h"
#include "yaRenderer.h"

namespace ya
{
	MainCamera::MainCamera()
		:mPos(Vector3(0.0f, 0.0f, -10.0f))
	{
		Camera* camera = AddComponent<Camera>();
		camera->SetSize(1.0f);
		camera->TurnLayerMask(eLayerType::UI, false);
		camera->SetCameraType(enums::eCameraType::Main);
		renderer::cameras.push_back(camera);

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);
		AddComponent<CameraScript>();
	}
	MainCamera::~MainCamera()
	{
	}
	void MainCamera::Intialize()
	{
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
	void MainCamera::SetTarget(GameObject* obj)
	{
		CameraScript* camScript = GetComponent<CameraScript>();
		camScript->SetTarget(obj);
	}
	void MainCamera::SetSize(float size)
	{
		Camera* camera = GetComponent<Camera>();
		camera->SetSize(size);
	}
}