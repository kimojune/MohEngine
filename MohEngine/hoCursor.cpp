#include "hoCursor.h"
#include "yaInput.h"
#include "yaTransform.h"

namespace ho
{
	Cursor::Cursor()
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
		Vector2 nomalPos = ya::Input::GetMousePos();
		mPos = Vector3(nomalPos.x, nomalPos.y, 0.0f);

		Transform* tr = GetComponent<Transform>();
		Vector3 worldPos = tr->TranslateWorldMatrix(mPos);
		
		tr->SetPosition(worldPos.x, worldPos.y, worldPos.z);
		

	}
	void Cursor::LateUpdate()
	{
	}
	void Cursor::Render()
	{
	}
}