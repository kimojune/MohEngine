#include "yaToolScript.h"
#include "yaInput.h"
#include "yaTilePalatte.h"

namespace ya
{
	ToolScript::ToolScript()
		:mIndex(-1)
	{
	}
	ToolScript::~ToolScript()
	{
	}
	void ToolScript::Initialize()
	{
	}
	void ToolScript::Update()
	{
		mIndex = TilePalatte::GetIndex();
		
		if (mIndex < 0)
			return;

		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 cursorPos = tr->GetPosition();
			cursorPos.x -= TILE_SIZE_X / 2;
			cursorPos.y -= TILE_SIZE_Y / 2;
			int x = (int)cursorPos.x / TILE_SIZE_X;
			int y = (int)cursorPos.y / TILE_SIZE_Y;

			TilePalatte::CreateTile(mIndex, Vector2((float)x, (float)y));
		}
	}
	void ToolScript::LateUpdate()
	{
	}
	void ToolScript::Render()
	{
	}
}
