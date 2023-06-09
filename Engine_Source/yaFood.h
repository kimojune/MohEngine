#pragma once
#include "yaGameObject.h"

namespace ya
{

	class Food : public GameObject
	{
	public:
		Food();
		virtual ~Food();


		virtual void Intialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		
	private:
		Info mInfo;
	};
}
