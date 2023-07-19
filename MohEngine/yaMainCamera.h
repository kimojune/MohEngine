#pragma once
#include "yaGameObject.h"

namespace ya
{
	class MainCamera : public GameObject
	{
	public:
		MainCamera();
		~MainCamera();

		virtual void Intialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		void SetPos(Vector3 pos) { mPos = pos; }
		void SetTarget(GameObject* obj);
		void SetSize(float size);

	private:
		Vector3 mPos;
	};
}
