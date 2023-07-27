#include "yaMainCamera.h"
#include "yaCamera.h"
#include "yaSceneManager.h"
#include "yaCameraScript.h"
#include "yaRenderer.h"
#include "yaObject.h"

namespace ya
{
	MainCamera::MainCamera()
		: mPos(Vector3(0.0f, 0.0f, -10.0f))
		, mSize(1.0f)
		, mCamera(nullptr)
	{
		mCamera = AddComponent<Camera>();
		mCamera->SetSize(mSize);
		mCamera->TurnLayerMask(eLayerType::UI, false);
		mCamera->SetCameraType(enums::eCameraType::Main);
		renderer::cameras.push_back(mCamera);

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);
		AddComponent<CameraScript>();
	}
	MainCamera::~MainCamera()
	{
	}
	void MainCamera::Initialize()
	{
		GameObject::Initialize();
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
		mSize = size;
		mCamera->SetSize(mSize);
	}
}