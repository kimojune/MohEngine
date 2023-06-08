#include "yaScene.h"


namespace ya
{
	Scene::Scene()
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Intialize()
	{
		
	}
	void Scene::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			gameObj->Update();
		}
	}
	void Scene::LateUpdate()
	{
	}
	void Scene::Render()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			gameObj->Render();
		}
	}
}
