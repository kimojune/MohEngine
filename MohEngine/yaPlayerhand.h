#pragma once
#include "yaGameObject.h"
#include "yaMaterial.h"
#include "yaMesh.h"

namespace ya
{	
	class Weapon;
	class Playerhand : public GameObject
	{
	public:
		Playerhand();
		virtual ~Playerhand();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		bool IsFlip() { return isFlip; }
		void SetWeapon(Weapon* weapon) { mWeapon = weapon; }

	private:
		bool isFlip;
		Weapon* mWeapon;
	};
}
