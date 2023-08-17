#pragma once
#include "..\Engine_SOURCE\yaScene.h"
namespace ya
{
	class MainCamera;
	class Gungeoneer;

	extern Gungeoneer* mActivePlayer;
	extern MainCamera* mMainCamera;

	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		float GetCameraSize() override;
		
	private:

		
	};
}
