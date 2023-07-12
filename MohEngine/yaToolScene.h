#pragma once
#include "..\Engine_SOURCE\yaScene.h"



namespace ya
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		
		virtual void OnEnter();
		virtual void OnExit();
	private:
	};
}
