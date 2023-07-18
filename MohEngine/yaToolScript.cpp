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
			int x = (int)cursorPos.x / TILE_SIZE_X;
			int y = (int)cursorPos.y / TILE_SIZE_Y;

			if (cursorPos.x < 0)
				x = ((int)cursorPos.x - TILE_SIZE_X / 2) / TILE_SIZE_X;
			else
				x = ((int)cursorPos.x + TILE_SIZE_X / 2) / TILE_SIZE_X;

			if (cursorPos.y < 0)
				y = ((int)cursorPos.y - TILE_SIZE_Y / 2) / TILE_SIZE_Y;
			else
				y = ((int)cursorPos.y + TILE_SIZE_Y / 2) / TILE_SIZE_Y;

			TilePalatte::CreateTile(mIndex, Vector2(x, y));
		}
	}
	void ToolScript::LateUpdate()
	{
	}
	void ToolScript::Render()
	{
	}
}
