#pragma once
#include "yaEntity.h"
#include "yaComponent.h"
#include "yaConstantBuffer.h"

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

	struct Info
	{
		float Scale;
		float y;
		float x;
	};

	virtual void Intialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

private:
	eState mState;
	//std::vector<Component*> mComponent;
};
}