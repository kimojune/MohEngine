#pragma once
#include "yaEntity.h"
#include "yaGameObject.h"

namespace ya
{

class Scene : public Entity
{
public:
	Scene();
	virtual ~Scene();

	virtual void Intialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

private:
	std::vector<GameObject*> mGameObjects;
};

}
