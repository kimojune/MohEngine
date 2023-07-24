#pragma once
#include "yaGameObject.h"

namespace ya
{
	class UICamera : public GameObject
	{
	public:
		UICamera();
		~UICamera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		Vector3 mPos;
	};
}
