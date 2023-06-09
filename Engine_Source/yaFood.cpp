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