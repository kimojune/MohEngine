#include "yaScene.h"
#include "yaInput.h"

namespace ya
{
	Scene::Scene()
	{
		mLayers.resize((UINT)ya::enums::eLayerType::End);
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		
	}
	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer& layer : mLayers)
		{
			layer.LateUpdate();
		}
	}
	void Scene::Render()
	{
		for (Layer& layer : mLayers)
		{
			layer.Render();
		}
	}
	void Scene::Destroy()
	{
		for (Layer& layer : mLayers)
		{
			layer.Destory();
		}
	}
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}
	float Scene::GetCameraSize()
	{
		return 1.0f;
	}
	Vector2 Scene::GetCursorDirectionVector(eCameraType type, GameObject* obj)
	{
		Transform* tr = obj->GetComponent<Transform>();
		Vector3 objPos = tr->GetCaculatePos();

		Vector2 objPos2 = Vector2(objPos.x, objPos.y);
		Vector2 cursorPos = Input::GetClientMousePos(type);

		Vector2 vDirection = cursorPos - objPos2;
		vDirection.Normalize();

		return vDirection;
	}
	void Scene::AddGameObject(eLayerType type, GameObject* gameObj)
	{
		mLayers[(UINT)type].AddGameObject(gameObj);
	}
}
