#pragma once
#include "yaEntity.h"
#include "yaComponent.h"

namespace ya
{
class GameObject : public Entity
{
public:
	enum eState
	{
		Active,
		Paused,
		Dead,
	};

	GameObject();
	virtual ~GameObject();

	virtual void Intialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

private:
	eState mState;
	//std::vector<Component*> mComponent;
	int y;
	int x;
};
}