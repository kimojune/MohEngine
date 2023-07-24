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

		//at->StartEvent(L"dodgefront") = std::bind(&PlayerScript::StartDodge, this);
		//at->CompleteEvent(L"dodgefront") = std::bind(&PlayerScript::CompleteDodge, this);
		// 
		//at->StartEvent(L"dodgeback") = std::bind(&PlayerScript::StartDodge, this);
		//at->CompleteEvent(L"dodgeback") = std::bind(&PlayerScript::CompleteDodge, this);
		// 
		//at->StartEvent(L"dodgeback_right") = std::bind(&PlayerScript::StartDodge, this);
		//at->CompleteEvent(L"dodgeback_right") = std::bind(&PlayerScript::CompleteDodge, this);
		// 
		//at->StartEvent(L"dodgefront_right") = std::bind(&PlayerScript::StartDodge, this);
		//at->CompleteEvent(L"dodgefront_right") = std::bind(&PlayerScript::CompleteDodge, this);
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
			mDirection = eDirection::RigntDown;
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
			PlayAnimationDir(L"idle", mDirection, true);
			break;
		case ya::PlayerScript::ePlayerState::Run:
			Run();
			PlayAnimationDir(L"run", mDirection, true);
			break;
		case ya::PlayerScript::ePlayerState::Dodge:
			//Dodge();
			//PlayAnimationDir(L"dodge", mDirection, false);
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

		if (mPrevState != mPlayerState || mPrevDirection != mDirection)
			mbPlayed = false;

		tr->SetPosition(mPos);
	}

	void PlayerScript::Idle()
	{
		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::D)
			|| Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::A))
			mPlayerState = ePlayerState::Run;


		//if (Input::GetKeyDown(eKeyCode::RBUTTON))
		//	mPlayerState = ePlayerState::Dodge;
	}

	void PlayerScript::Run()
	{
		if (Input::GetKey(eKeyCode::W) && Input::GetKey(eKeyCode::D))
		{
			mPos.x += 150.0f * Time::DeltaTime();
			mPos.y += 150.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::W) && Input::GetKey(eKeyCode::A))
		{
			mPos.x -= 150.0f * Time::DeltaTime();
			mPos.y += 150.0f * Time::DeltaTime();

		}
		else if (Input::GetKey(eKeyCode::S) && Input::GetKey(eKeyCode::D))
		{
			mPos.x += 150.0f * Time::DeltaTime();
			mPos.y -= 150.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::S) && Input::GetKey(eKeyCode::A))
		{
			mPos.x -= 150.0f * Time::DeltaTime();
			mPos.y -= 150.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::W))
		{
			mPos.y += 210.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			mPos.y -= 210.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			mPos.x -= 210.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			mPos.x += 210.0f * Time::DeltaTime();
		}
		else
			mPlayerState = ePlayerState::Idle;
	}
	void PlayerScript::Dodge()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();
		if (at->GetActiveAnimation()->IsComplete())
			mPlayerState = ePlayerState::Idle;
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
		std::wstring anmationName = name;
		std::wstring directionName = {};

		switch (direction)
		{
		case ya::enums::eDirection::Up:
			directionName = name + L"back";
			at->PlayAnimation(directionName, loop);
			break;
		case ya::enums::eDirection::Down:
			directionName = name + L"front";
			at->PlayAnimation(directionName, loop);
			break;
		case ya::enums::eDirection::LeftUp:
			directionName = name + L"back_right";
			at->PlayAnimation(directionName, loop, true);
			break;
		case ya::enums::eDirection::LeftDown:
			directionName = name + L"front_right";
			at->PlayAnimation(directionName, loop, true);
			break;
		case ya::enums::eDirection::RightUp:
			directionName = name + L"back_right";
			at->PlayAnimation(directionName, loop);
			break;
		case ya::enums::eDirection::RigntDown:
			directionName = name + L"front_right";
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

	}
	void PlayerScript::CompleteDodge()
	{
		
	}
}
