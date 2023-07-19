#pragma once
#include "..\Engine_SOURCE\yaScene.h"

namespace ya
{

	class InventoryScene : public Scene
	{
	public:
		InventoryScene();
		virtual ~InventoryScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
		virtual void Destroy() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
	private:

	};
}
