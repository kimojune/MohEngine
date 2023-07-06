#pragma once
#include "..\Engine_SOURCE\yaScene.h"


namespace ya
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();

		virtual void OnEnter();
		virtual void OnExit();
	private:
	};
}
