#include "yaFood.h"
#include "yaRenderer.h"

namespace ya
{
	Food::Food()
	{
		Entity::SetName(L"Food");
	}
	Food::~Food()
	{
	}
	void Food::Intialize()
	{
		mInfo = GetInfo();
		mInfo.Scale = 0.005f;
		
		/*mInfo.x = RandomNumder() / 10 * IsNegative();
		mInfo.y = RandomNumder() / 10 * IsNegative();*/
		float x = (RandomNumder() / 10) * IsNegative();
		float y = (RandomNumder() / 10) * IsNegative();

		mInfo.x = x;
		mInfo.y = y;

		Vector4 vector = { 1.0f, 1.0f, 0.0f, 1 };
		mInfo.mColor = vector;
		//mInfo.Scale = RandomNumder() / 100;

		SetInfo(mInfo);
	}
	void Food::Update()
	{
		GameObject::Update();
	}
	void Food::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Food::Render()
	{
		GameObject::Render();
	}
}