#include "yaLayer.h"

namespace ya
{
	Layer::Layer()
	{
	}
	Layer::~Layer()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}
	void Layer::Initialize()
	{
	}
	void Layer::Update()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			gameobj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			gameobj->LateUpdate();
		}
	}
	void Layer::Render()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			gameobj->Render();
		}
	}
	void Layer::AddGameObject(GameObject* gameObj)
	{
		mGameObjects.push_back(gameObj);
	}
}