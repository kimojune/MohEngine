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

		Animator* at = GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"basicidle", false, mFlip);

	}
	void WeaponScript::Update()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		mTime += Time::DeltaTime();

		at->PlayAnimation(L"basicidle", false, mFlip);


		if (mBullets < 0)
		{
			
			at->PlayAnimation(L"basicreload", false, mFlip);

			if (mTime >= mReloadTime)
			{
				at->PlayAnimation(L"basicidle", false, mFlip);
				mBullets = mInfo.magazineSize;
				
			}
		}

		else if (Input::GetKeyDown(eKeyCode::LBUTTON)&& mFireLate < mTime)
		{
			at->PlayAnimation(L"basicshoot", false, mFlip);
			mBullets -= 1;
			mTime = 0;
		}


	}
}