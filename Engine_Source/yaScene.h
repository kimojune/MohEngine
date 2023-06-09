#pragma once
#include "yaEntity.h"
#include "yaGameObject.h"

namespace ya
{

class Player;
class Scene : public Entity
{
public:
	Scene();
	virtual ~Scene();

	virtual void Intialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	void CollisionCheck(GameObject* obj);
	
private:
	std::vector<GameObject*> mGameObjects;
	Player* mplayer;
	float mTime;
};

}
