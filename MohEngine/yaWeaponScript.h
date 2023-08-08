#pragma once
#include "yaScript.h"
#include "yaWeapon.h"
namespace ya
{
	class Animator;
	class WeaponScript : public Script
	{
	public:
		enum class eWeaponState
		{
			idle,
			reload,
			shoot,
			End,
		};

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) {};
		virtual void OnCollisionStay(Collider2D* other) {};
		virtual void OnCollisionExit(Collider2D* other) {};

		void SetWeaponInfo(Weapon::WeaponInfo info) { mInfo = info; }
		void SetFlip(eFlipType fliptype) { mFlip = fliptype; }
		void SetPlayed(bool bplay) { bPlayed = bplay; }
		void SetAttack();

		void Idle();
		void Reload();
		void Shoot();
		void End();

		void StartIdle();
		void CompleteIdle();
		void EndIdle();

		void StartReload();
		void CompleteReload();
		void EndReload();

		void StartShoot();
		void CompleteShoot();
		void EndShoot();

	private:
		Weapon::WeaponInfo mInfo;
		eWeaponState mState;
		eWeaponState mPrevState;
		bool bPlayed = false;
		bool bFlip;

		int mBullets;
		int mMagazineSize;
		int mMaxAmmo;

		float mTime;
		float mFireLate;
		float mReloadTime;

		eFlipType mFlip;
		
		Animator* mAnimator;
	};

}
