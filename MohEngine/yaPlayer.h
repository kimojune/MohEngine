#pragma once
#include "yaGameObject.h"
#include "yaWeapon.h"

namespace ya
{
	class Playerhand;
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		struct PlayerInfo
		{
			int HP;
			int Blanks; // uiManager?)
			int Money;
			int key;//weaponManager
		};

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		int mHP;
		Playerhand* hand;
	};
}
