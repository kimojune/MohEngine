#include "yaPlayerScript.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaGameObject.h"
#include "yaAnimator.h"
namespace ya
{
	void PlayerScript::Initialize()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		at->StartEvent(L"dodgefront") = std::bind(&PlayerScript::StartDodge, this);
		at->CompleteEvent(L"dodgefront") = std::bind(&PlayerScript::CompleteDodge, this);

		at->StartEvent(L"dodgeback") = std::bind(&PlayerScript::StartDodge, this);
		at->CompleteEvent(L"dodgeback") = std::bind(&PlayerScript::CompleteDodge, this);

		at->StartEvent(L"dodgeback_right") = std::bind(&PlayerScript::StartDodge, this);
		at->CompleteEvent(L"dodgeback_right") = std::bind(&PlayerScript::CompleteDodge, this);

		at->StartEvent(L"dodgefront_right") = std::bind(&PlayerScript::StartDodge, this);
		at->CompleteEvent(L"dodgefront_right") = std::bind(&PlayerScript::CompleteDodge, this);
	}
	void PlayerScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		mPos = tr->GetPosition();

		mPrevDirection = mDirection;
		mPrevState = mPlayerState;

		Vector2 playerPos = Vector2(mPos.x, mPos.y);
		Vector2 cursorPos = Input::GetClientMousePos(eCameraType::Main);

		Vector2 vDirection = cursorPos - playerPos;
		vDirection.Normalize();

		float radian = atan2f(vDirection.y, vDirection.x);
		float degree = radian * 180 / PI;

		if (degree >= -60.f && degree <= 0.0f)
		{
			mDirection = eDirection::RightDown;
		}

		else if (degree >= 0.0f && degree <= 60.f)
		{
			mDirection = eDirection::RightUp;
		}

		else if (degree >= 60.f && degree <= 120.0f)
		{
			mDirection = eDirection::Up;
		}

		else if (degree >= 120.0f && degree <= 180.0f)
		{
			mDirection = eDirection::LeftUp;
		}

		else if (degree >= -180.0f && degree <= -120.0f)
		{
			mDirection = eDirection::LeftDown;
		}

		else if (degree >= -120.0f && degree <= -60.0f)
		{
			mDirection = eDirection::Down;
		}
		//cursorPos()

		switch (mPlayerState)
		{
		case ya::PlayerScript::ePlayerState::Idle:
			Idle();
			animationLoop = true;
			PlayAnimationDir(L"idle", mDirection, animationLoop);
			break;
		case ya::PlayerScript::ePlayerState::Run:
			Run();
			animationLoop = true;
			PlayAnimationDir(L"run", mDirection, animationLoop);
			break;
		case ya::PlayerScript::ePlayerState::Dodge:
			Dodge();
			animationLoop = false;
			PlayAnimationDir(L"dodge", mInputDirection, animationLoop);

			break;
		case ya::PlayerScript::ePlayerState::PitFall:
			break;
		case ya::PlayerScript::ePlayerState::Death:
			break;
		case ya::PlayerScript::ePlayerState::End:
			break;
		default:
			break;
		}


		if (animationLoop)
		{
			if (mPrevState != mPlayerState || mPrevDirection != mDirection)
				mbPlayed = false;
		}
		else
		{
			if (mPrevState != mPlayerState)
				mbPlayed = false;
		}

		tr->SetPosition(mPos);
	}

	void PlayerScript::Idle()
	{
		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::D)
			|| Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::A))
		{
			mPlayerState = ePlayerState::Run;
		}

	}

	void PlayerScript::Run()
	{
		if (Input::GetKeyDown(eKeyCode::RBUTTON))
		{
			mPlayerState = ePlayerState::Dodge;
		}
		else if (Input::GetKey(eKeyCode::W) && Input::GetKey(eKeyCode::D))
		{
			mPos.x += 150.0f * Time::DeltaTime();
			mPos.y += 150.0f * Time::DeltaTime();
			mInputDirection = eDirection::RightUp;
		}
		else if (Input::GetKey(eKeyCode::W) && Input::GetKey(eKeyCode::A))
		{
			mPos.x -= 150.0f * Time::DeltaTime();
			mPos.y += 150.0f * Time::DeltaTime();
			mInputDirection = eDirection::LeftUp;
		}
		else if (Input::GetKey(eKeyCode::S) && Input::GetKey(eKeyCode::D))
		{
			mPos.x += 150.0f * Time::DeltaTime();
			mPos.y -= 150.0f * Time::DeltaTime();
			mInputDirection = eDirection::RightDown;
		}
		else if (Input::GetKey(eKeyCode::S) && Input::GetKey(eKeyCode::A))
		{
			mPos.x -= 150.0f * Time::DeltaTime();
			mPos.y -= 150.0f * Time::DeltaTime();
			mInputDirection = eDirection::LeftDown;

		}
		else if (Input::GetKey(eKeyCode::W))
		{
			mPos.y += 210.0f * Time::DeltaTime();
			mInputDirection = eDirection::Up;
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			mPos.y -= 210.0f * Time::DeltaTime();
			mInputDirection = eDirection::Down;
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			mPos.x -= 210.0f * Time::DeltaTime();
			mInputDirection = eDirection::Left;
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			mPos.x += 210.0f * Time::DeltaTime();
			mInputDirection = eDirection::Right;
		}

		else
		{
			mPlayerState = ePlayerState::Idle;
			mInputDirection = eDirection::End;
		}

	}
	void PlayerScript::Dodge()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();
		mTime += Time::DeltaTime();

		float dodgeSpeed = 300.0f;
		float diagonalDodge = 215.0f;
		if (at->GetActiveAnimation()->IsComplete())
		{
			mPlayerState = ePlayerState::Idle;
		}
		if (mTime < 0.5f)
		{
			switch (mInputDirection)
			{
			case ya::enums::eDirection::Left:
				mPos.x -= dodgeSpeed * Time::DeltaTime();
				break;
			case ya::enums::eDirection::Right:
				mPos.x += dodgeSpeed * Time::DeltaTime();
				break;
			case ya::enums::eDirection::Up:
				mPos.y += dodgeSpeed * Time::DeltaTime();
				break;
			case ya::enums::eDirection::Down:
				mPos.y -= dodgeSpeed * Time::DeltaTime();
				break;
			case ya::enums::eDirection::LeftUp:
				mPos.x -= diagonalDodge * Time::DeltaTime();
				mPos.y += diagonalDodge * Time::DeltaTime();
				break;
			case ya::enums::eDirection::LeftDown:
				mPos.x -= diagonalDodge * Time::DeltaTime();
				mPos.y -= diagonalDodge * Time::DeltaTime();
				break;
			case ya::enums::eDirection::RightUp:
				mPos.x += diagonalDodge * Time::DeltaTime();
				mPos.y += diagonalDodge * Time::DeltaTime();
				break;
			case ya::enums::eDirection::RightDown:
				mPos.x += diagonalDodge * Time::DeltaTime();
				mPos.y -= diagonalDodge * Time::DeltaTime();
				break;
			case ya::enums::eDirection::End:
				break;
			default:
				break;
			}
		}
		else
		{
			switch (mInputDirection)
			{
			case ya::enums::eDirection::Left:
				mPos.x -= dodgeSpeed / 4 * Time::DeltaTime();
				break;
			case ya::enums::eDirection::Right:
				mPos.x += dodgeSpeed / 4 * Time::DeltaTime();
				break;
			case ya::enums::eDirection::Up:
				mPos.y += dodgeSpeed / 4 * Time::DeltaTime();
				break;
			case ya::enums::eDirection::Down:
				mPos.y -= dodgeSpeed / 4 * Time::DeltaTime();
				break;
			case ya::enums::eDirection::LeftUp:
				mPos.x -= diagonalDodge / 4 * Time::DeltaTime();
				mPos.y += diagonalDodge / 4 * Time::DeltaTime();
				break;
			case ya::enums::eDirection::LeftDown:
				mPos.x -= diagonalDodge / 4 * Time::DeltaTime();
				mPos.y -= diagonalDodge / 4 * Time::DeltaTime();
				break;
			case ya::enums::eDirection::RightUp:
				mPos.x += diagonalDodge / 4 * Time::DeltaTime();
				mPos.y += diagonalDodge / 4 * Time::DeltaTime();
				break;
			case ya::enums::eDirection::RightDown:
				mPos.x += diagonalDodge / 4 * Time::DeltaTime();
				mPos.y -= diagonalDodge / 4 * Time::DeltaTime();
				break;
			case ya::enums::eDirection::End:
				break;
			default:
				break;
			}
		}
	}
	void PlayerScript::PitFall()
	{
	}
	void PlayerScript::Death()
	{
	}
	void PlayerScript::PlayAnimationDir(const std::wstring& name, eDirection direction, bool loop)
	{
		if (mbPlayed)
			return;

		Animator* at = GetOwner()->GetComponent<Animator>();
		std::wstring animationName = name;
		std::wstring directionName = {};

		switch (direction)
		{
		case ya::enums::eDirection::Up:
			directionName = animationName + L"back";
			at->PlayAnimation(directionName, loop);
			break;
		case ya::enums::eDirection::Down:
			directionName = animationName + L"front";
			at->PlayAnimation(directionName, loop);
			break;
		case ya::enums::eDirection::Left:
			directionName = animationName + L"front_right";
			at->PlayAnimation(directionName, loop, true);
			break;
		case ya::enums::eDirection::Right:
			directionName = animationName + L"front_right";
			at->PlayAnimation(directionName, loop);
			break;
		case ya::enums::eDirection::LeftUp:
			directionName = animationName + L"back_right";
			at->PlayAnimation(directionName, loop, true);
			break;
		case ya::enums::eDirection::LeftDown:
			directionName = animationName + L"front_right";
			at->PlayAnimation(directionName, loop, true);
			break;
		case ya::enums::eDirection::RightUp:
			directionName = animationName + L"back_right";
			at->PlayAnimation(directionName, loop);
			break;
		case ya::enums::eDirection::RightDown:
			directionName = animationName + L"front_right";
			at->PlayAnimation(directionName, loop);
			break;
		case ya::enums::eDirection::End:
			break;
		default:
			break;
		}
		mbPlayed = true;
	}
	void PlayerScript::StartDodge()
	{
		invincible = true;
		mTime = 0.0f;
	}
	void PlayerScript::CompleteDodge()
	{
		invincible = false;
	}
}
