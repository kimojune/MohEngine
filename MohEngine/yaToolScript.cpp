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
			TilePalatte::CreateTile(mIndex, Input::GetMousePos());
		}
	}
	void ToolScript::LateUpdate()
	{
	}
	void ToolScript::Render()
	{
	}
}
