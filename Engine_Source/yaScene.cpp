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
		GameObject* obj = new GameObject;
		mGameObjects.push_back(obj);
	}
	void Scene::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			/*if (gameObj == nullptr)
				continue;*/
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
