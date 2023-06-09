#include "yaScene.h"
#include "yaPlayer.h"
#include "yaFood.h"
#include "yaGameObject.h"
#include "yaRenderer.h"


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
		
		mplayer = new Player;
		mplayer->Intialize();
		mGameObjects.push_back(mplayer);

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
			CollisionCheck(gameObj);
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
	void Scene::CollisionCheck(GameObject* obj)
	{
		if (obj->GetName() == L"Food")
		{ 
			GameObject::Info playerinfo = mplayer->GetInfo();
			GameObject::Info objinfo = obj->GetInfo();
			Vector2 playerpos = { playerinfo.x, playerinfo.y };
			Vector2 objpos = { objinfo.x, objinfo.y };
			Vector3 vetexespos = ya::renderer::vertexes[1].pos;
			
			float PlayerXLength = vetexespos.x * playerinfo.Scale;
			float PlayerYLength = vetexespos.y * playerinfo.Scale;
			float ObjXLength = vetexespos.x * objinfo.Scale;
			float ObjYLength = vetexespos.y * objinfo.Scale;

			if (fabs(PlayerXLength + ObjXLength) > fabs(playerpos.x - objpos.x)
				&& fabs(PlayerYLength + ObjYLength) > fabs(playerpos.y - objpos.y))
			{
				playerinfo.Scale += objinfo.Scale;
			}
			
			mplayer->SetInfo(playerinfo);
		}

	}
}
