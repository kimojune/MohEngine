#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Dog : public GameObject
	{
	public:
		Dog();
		~Dog();

		virtual void Intialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}
