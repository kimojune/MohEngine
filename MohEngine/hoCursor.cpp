#include "hoCursor.h"
#include "yaInput.h"
#include "yaTransform.h"

namespace ho
{
	Cursor::Cursor()
		:mPos(Vector3::(0.0f,0.0f,-20.0f))
	{
	}
	Cursor::~Cursor()
	{
	}
	void Cursor::Intialize()
	{

	}
	void Cursor::Update()
	{
		Vector2 Pos = ya::Input::GetMousePos();
		mPos = Vector3(Pos.x, Pos.y, -20.0f);

		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(mPos);

		GameObject::Update();
	}
	void Cursor::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Cursor::Render()
	{
		GameObject::Render();
	}
}