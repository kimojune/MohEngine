#include "yaWeaponScript.h"
#include "yaAnimator.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"

namespace ya
{
	void WeaponScript::Initialize()
	{
		mBullets = mInfo.magazineSize;
		mMagazineSize = mInfo.magazineSize;
		mMaxAmmo = mInfo.maxAmmo;
		mFireLate = mInfo.fireRate_Automatic;

		mTime = 0.0f;
		mFlip = eFlipType::None;
		mState = eWeaponState::idle;

		mAnimator = GetOwner()->GetComponent<Animator>();
		mAnimator->PlayAnimation(L"basicidle", false, mFlip);

		mAnimator->StartEvent(L"basicidle") = std::bind(&WeaponScript::StartIdle, this);
		mAnimator->CompleteEvent(L"basicidle") = std::bind(&WeaponScript::CompleteIdle, this);
		mAnimator->EndEvent(L"basicidle") = std::bind(&WeaponScript::EndIdle, this);

		mAnimator->StartEvent(L"basicreload") = std::bind(&WeaponScript::StartReload, this);
		mAnimator->CompleteEvent(L"basicreload") = std::bind(&WeaponScript::CompleteReload, this);
		mAnimator->EndEvent(L"basicreload") = std::bind(&WeaponScript::EndReload, this);

		mAnimator->StartEvent(L"basicshoot") = std::bind(&WeaponScript::StartShoot, this);
		mAnimator->CompleteEvent(L"basicshoot") = std::bind(&WeaponScript::CompleteShoot, this);
		mAnimator->EndEvent(L"basicshoot") = std::bind(&WeaponScript::EndShoot, this);
		
	}
	void WeaponScript::Update()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		mTime += Time::DeltaTime();
		mPrevState = mState;

		switch (mState)
		{
		case ya::WeaponScript::eWeaponState::idle:
			if (!bPlayed)
			{
				at->PlayAnimation(L"basicidle", false, mFlip);
				bPlayed = true;
			}
			Idle();
			break;
		case ya::WeaponScript::eWeaponState::reload:
			if (!bPlayed)
			{
				at->PlayAnimation(L"basicreload", false, mFlip);
				bPlayed = true;
				mBullets = mMagazineSize;
			}
			Reload();
			break;
		case ya::WeaponScript::eWeaponState::shoot:
			if (!bPlayed)
			{
				mTime = 0;
				at->PlayAnimation(L"basicshoot", false, mFlip);
				bPlayed = true;
			}
			Shoot();
			break;
		default:
			break;
		}
		
		if (mPrevState != mState)
			bPlayed = false;
	}
	void WeaponScript::SetAttack()
	{
		mState = eWeaponState::shoot;
	}
	void WeaponScript::Idle()
	{
		if (mBullets < 0)
		{
			mState = eWeaponState::reload;
			mTime = 0;
		}
	}
	void WeaponScript::Reload()
	{
		Animation* ani = mAnimator->GetActiveAnimation();
		if (ani->IsComplete())
		{
			mBullets = mMagazineSize ;
			mState = eWeaponState::idle;
		}
	}
	void WeaponScript::Shoot()
	{


		Animation* ani = mAnimator->GetActiveAnimation();
		if (ani->IsComplete())
		{
			mState = eWeaponState::idle;
			mBullets--;
		}

	}
	void WeaponScript::End()
	{
	}
	void WeaponScript::StartIdle()
	{
	}
	void WeaponScript::CompleteIdle()
	{
	}
	void WeaponScript::EndIdle()
	{
	}
	void WeaponScript::StartReload()
	{
	}
	void WeaponScript::CompleteReload()
	{
	}
	void WeaponScript::EndReload()
	{
	}
	void WeaponScript::StartShoot()
	{
	}
	void WeaponScript::CompleteShoot()
	{
	}
	void WeaponScript::EndShoot()
	{
	}
}