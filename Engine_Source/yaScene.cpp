#include "yaScene.h"


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
	void Scene::AddGameObject(eLayerType type, GameObject* gameObj)
	{
		mLayers[(UINT)type].AddGameObject(gameObj);
	}
}
