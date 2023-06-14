#include "yaScene.h"
#include "yaPlayer.h"
#include "yaFood.h"
#include "yaGameObject.h"
#include "yaRenderer.h"
#include "yaMonster.h"

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


		for (size_t i = 0; i < 10; i++)
		{

			monster[i] = new Monster;
			monster[i]->Intialize();
			mGameObjects.push_back(monster[i]);

		}
	}
	void Scene::Update()
	{
		mTime += Time::DeltaTime();
		mMonsterTime += Time::DeltaTime();

		for (GameObject* gameObj : mGameObjects)
		{
			/*if (gameObj == nullptr)
				continue;*/
			if (gameObj->GetState() == GameObject::eState::Active)
			{
				gameObj->Update();
				CollisionCheck(gameObj);
			}
		}

		if (mTime > 1.0f)
		{
			mTime = 0;

			Food* food = new Food;
			food->Intialize();
			mGameObjects.push_back(food);
		}

		if (mMonsterTime > 5.0f)
		{
			mMonsterTime = 0;

			for (size_t i = 0; i < 10; i++)
			{
				if (monster[i]->GetState() == GameObject::eState::Paused)
				{ 
					monster[i]->SetState(GameObject::eState::Active);
					monster[i]->Intialize();
				}
			}
			
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
			
			if(gameObj->GetState() == GameObject::eState::Active)
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
				if (playerinfo.Scale >= objinfo.Scale)
				{
					playerinfo.Scale += objinfo.Scale ;
					objinfo.Scale = 0;
					mplayer->SetInfo(playerinfo);
					obj->SetInfo(objinfo);
				}
			}

			
		}

		if (obj->GetName() == L"Monster")
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
				if (playerinfo.Scale >= objinfo.Scale)
				{
					playerinfo.Scale += objinfo.Scale / 10;
					objinfo.Scale = 0;
					mplayer->SetInfo(playerinfo);
					obj->SetInfo(objinfo);
					obj->SetState(GameObject::eState::Paused);
				}

				else
				{
					playerinfo.Scale = 0;
					mplayer->SetInfo(playerinfo);
				}
			}
		}

	}
}
