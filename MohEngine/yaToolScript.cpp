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
			
			Vector2 tilePos
				= Vector2((UINT)(cursorPos.x / TILE_SIZE_X),((UINT)cursorPos.y / TILE_SIZE_Y));
			TilePalatte::CreateTile(mIndex, Vector2(tilePos));
		}
	}
	void ToolScript::LateUpdate()
	{
	}
	void ToolScript::Render()
	{
	}
}
