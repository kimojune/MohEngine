#include "yaScene.h"
#include "yaPlayer.h"
#include "yaFood.h"


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
		
		Player* player = new Player;
		player->Intialize();
		mGameObjects.push_back(player);

		Food* food = new Food;
		food->Intialize();
		mGameObjects.push_back(food);


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
