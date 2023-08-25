#pragma once
#include "yaPlayScene.h"

namespace ya
{
	class Chamber1Scene : public PlayScene
	{
	public:
		Chamber1Scene();
		~Chamber1Scene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
	private:

	};
}
