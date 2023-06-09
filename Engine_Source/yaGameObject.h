#pragma once
#include "yaEntity.h"
#include "yaComponent.h"
#include "yaConstantBuffer.h"
#include "yaTime.h"

namespace ya
{
	using namespace graphics;

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
		float x;
		float y;
	};

	virtual void Intialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	virtual Info GetInfo() = 0;
	virtual void SetInfo(Info info){ mInfo = info;}

	float RandomNumder();
	int IsNegative();
private:
	eState mState;
	Info mInfo;

	};
}