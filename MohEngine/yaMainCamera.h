#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Camera;
	class MainCamera : public GameObject
	{
	public:
		MainCamera();
		~MainCamera();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		void SetPos(Vector3 pos) { mPos = pos; }
		void SetTarget(GameObject* obj);
		void SetSize(float size);

		float GetSize() { return mSize; }

	private:
		Camera* mCamera;
		Vector3 mPos;
		float mSize;
	};
}
