#pragma once
#include "yaScript.h"
#include "yaGameObject.h"

namespace ya
{
	class CameraScript : public Script
	{
	public:
		virtual void Update() override;

		void SetTarget(GameObject* obj) { mTarget = obj; }

	private:
		GameObject* mTarget;
	};
}
