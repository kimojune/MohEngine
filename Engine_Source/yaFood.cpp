#include "yaFood.h"
#include "yaRenderer.h"

namespace ya
{
	Food::Food()
	{
	}
	Food::~Food()
	{
	}
	void Food::Intialize()
	{
		mInfo.Scale = 0.1f;
		
		mInfo.x = RandomNumder() / 10 * IsNegative();
		mInfo.y = RandomNumder() / 10 * IsNegative();

		Vector4 vector = { mInfo.x , mInfo.y, RandomNumder() / 10 , 1 };
		mInfo.mColor = vector;
		
	}
	void Food::Update()
	{
	
	}
	void Food::LateUpdate()
	{
	}
	void Food::Render()
	{
		GameObject::Render();
	}
}