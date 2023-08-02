#pragma once
#include "yaScript.h"
#include "yaWeapon.h"
namespace ya
{

	class WeaponScript : public Script
	{
	public:

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) {};
		virtual void OnCollisionStay(Collider2D* other) {};
		virtual void OnCollisionExit(Collider2D* other) {};

		void SetWeaponInfo(Weapon::WeaponInfo info) { mInfo = info; }
		void SetFlip(eFlipType fliptype) { mFlip = fliptype; }
		
	private:
		Weapon::WeaponInfo mInfo;
		bool bPlayed = false;

		int mBullets;
		int mMagazineSize;
		int mMaxAmmo;

		float mTime;
		float mFireLate;
		float mReloadTime;

		eFlipType mFlip;
	};

}
