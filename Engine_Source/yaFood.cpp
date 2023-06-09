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
		mInfo.Scale = 0.01f;
		mInfo.x = 0;
		mInfo.y = 0;
	}
	void Food::Update()
	{
		ya::renderer::Setpos(mInfo.x, mInfo.y);

	}
	void Food::LateUpdate()
	{
	}
	void Food::Render()
	{
		GameObject::Render();
	}
}