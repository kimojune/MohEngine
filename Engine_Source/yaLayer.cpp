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
			if (gameobj->GetState()
				!= GameObject::eState::Active)
				continue;

			gameobj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj->GetState()
				!= GameObject::eState::Active)
				continue;

			gameobj->LateUpdate();
		}
	}
	void Layer::Render()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj->GetState()
				!= GameObject::eState::Active)
				continue;

			gameobj->Render();
		}
	}
	void Layer::Destory()
	{
		// dead 오브젝트 모아두기
		std::set<GameObject*> deleteGameObj = {};
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj->GetState()
				== GameObject::eState::Dead)
				deleteGameObj.insert(gameObj);
		}

		// daed 오브젝트 제외시키기 layer에서
		typedef std::vector<GameObject*>::iterator GameObjectIter;
		for (GameObjectIter iter = mGameObjects.begin()
			; iter != mGameObjects.end(); )
		{
			std::set<GameObject*>::iterator deleteIter
				= deleteGameObj.find(*(iter));

			if (deleteIter != deleteGameObj.end())
			{
				iter = mGameObjects.erase(iter);
				continue;
			}

			iter++;
		}

		//메모리 해제
		for (GameObject* gameObj : deleteGameObj)
		{
			delete gameObj;
			gameObj = nullptr;
		}
	}
	void Layer::AddGameObject(GameObject* gameObj)
	{
		mGameObjects.push_back(gameObj);
	}
}