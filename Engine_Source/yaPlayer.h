#pragma once
#include "yaGameObject.h"
namespace ya
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		virtual void Intialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
	};
}
