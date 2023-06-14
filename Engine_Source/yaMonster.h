#pragma once
#include "yaGameObject.h"

namespace ya
{
	using namespace math;
class Monster : public GameObject
{
public:
	Monster();
	virtual ~Monster();
	
	virtual void Intialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

private:
	Info mInfo;
	Vector2 mDirection;
};

}
