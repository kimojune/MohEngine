#pragma once
#include "..\Engine_SOURCE\yaScene.h"



namespace ya
{
	class MainCamera;
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		enum class eAtlasType
		{
			ENV_Tileset_Castle,
			ENV_Stamps_Castle,
			shoptileset001,
			End,
		};

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		
		virtual void OnEnter();
		virtual void OnExit();
	private:
		UINT mAtlasIndex;
		MainCamera* mCamera;
		float cameraSize;
	};
}
