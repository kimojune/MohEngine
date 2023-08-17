#pragma once
#include "yaGameObject.h"
#include "yaWeapon.h"

namespace ya
{
	class PlayerHand;
	class Gungeoneer : public GameObject
	{
	public:
		Gungeoneer();
		~Gungeoneer();

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
		
	protected:
		PlayerHand* mHand;
	};
}
