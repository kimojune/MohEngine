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
		mReverse = false;

		Animator* at = GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"basicidle", false, mReverse);

	}
	void WeaponScript::Update()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		mTime += Time::DeltaTime();

		if (Input::GetKeyDown(eKeyCode::LBUTTON)&& mFireLate < mTime)
		{
			at->PlayAnimation(L"basicshoot", false, mReverse);
			mBullets -= 1;
			mTime = 0;


		}

		if (mBullets < 0)
		{
			at->PlayAnimation(L"basicreload", false, mReverse);

			if (mTime >= mReloadTime)
			{
				at->PlayAnimation(L"basicidle", false, mReverse);
				mBullets = mInfo.magazineSize;
			}
		}

	}
}