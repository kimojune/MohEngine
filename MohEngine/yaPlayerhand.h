#pragma once
#include "yaGameObject.h"
#include "yaMaterial.h"
#include "yaMesh.h"

namespace ya
{	
	class Weapon;
	class PlayerHand : public GameObject
	{
	public:
		PlayerHand();
		virtual ~PlayerHand();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		bool IsFlip() { return isFlip; }
		void SetAttack();

		std::vector <Weapon*> mWeapons;
	private:
		bool isFlip;
		bool prevFlip;
		Weapon* mActiveWeapon;
	};
}
