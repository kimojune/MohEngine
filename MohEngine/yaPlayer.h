#pragma once
#include "yaGameObject.h"
#include "yaWeapon.h"

namespace ya
{
	class PlayerHand;
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

		void SetAttack();
		Weapon* GetActiveWeapon() { return mActiveWeapon; }

	protected:
		std::vector<Weapon*>mWeapons;
		PlayerHand* hand;
		Weapon* mActiveWeapon;
	};
}
