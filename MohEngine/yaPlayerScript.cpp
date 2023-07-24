#include "yaPlayerScript.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaGameObject.h"
#include "yaAnimator.h"
namespace ya
{
	void PlayerScript::Idle()
	{
	}
	void PlayerScript::Move()
	{
	}
	void PlayerScript::Run()
	{
	}
	void PlayerScript::Dodge()
	{
	}
	void PlayerScript::PitFall()
	{
	}
	void PlayerScript::Death()
	{
	}
	void PlayerScript::Update()
	{
			//idle\\front
			//idle\\back
			//idle\\back_right
			//idle\\right_front

			//idle\\front_hand
			//idle\\front_hand2

			//idle\\right_front_hand
			//idle\\right_front_hand2
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Vector2 cursorPos = Input::GetClientMousePos(eCameraType::Main);
		//cursorPos()
		switch (mState)
		{
		case ya::PlayerScript::ePlayState::Idle:
			break;
		case ya::PlayerScript::ePlayState::Move:
			break;
		case ya::PlayerScript::ePlayState::Run:
			break;
		case ya::PlayerScript::ePlayState::Dodge:
			break;
		case ya::PlayerScript::ePlayState::PitFall:
			break;
		case ya::PlayerScript::ePlayState::Death:
			break;
		case ya::PlayerScript::ePlayState::End:
			break;
		default:
			break;
		}
		

		

		Animator* at = GetOwner()->GetComponent<Animator>();

		at->PlayAnimation(L"idlefront", true);
		at->PlayAnimation(L"idlefront_right", true, true);

		at->PlayAnimation(L"idleback", true);
		at->PlayAnimation(L"idlefront_right", true);


		
		 if (Input::GetKey(eKeyCode::W) &&Input::GetKey(eKeyCode::D))
		{
			pos.x += 150.0f * Time::DeltaTime();
			pos.y += 150.0f * Time::DeltaTime();
			tr->SetPosition(pos);


		}
		else if (Input::GetKey(eKeyCode::W) &&Input::GetKey(eKeyCode::A))
		{
			pos.x -= 150.0f * Time::DeltaTime();
			pos.y += 150.0f * Time::DeltaTime();
			tr->SetPosition(pos);


		}
		else if (Input::GetKey(eKeyCode::S) &&Input::GetKey(eKeyCode::D))
		{
			pos.x += 150.0f * Time::DeltaTime();
			pos.y -= 150.0f * Time::DeltaTime();
			tr->SetPosition(pos);


		}
		else if (Input::GetKey(eKeyCode::S) &&Input::GetKey(eKeyCode::A))
		{
			pos.x -= 150.0f * Time::DeltaTime();
			pos.y -= 150.0f * Time::DeltaTime();
			tr->SetPosition(pos);

		}
		else if (Input::GetKey(eKeyCode::W))
		{
			pos.y += 210.0f * Time::DeltaTime();
			tr->SetPosition(pos);


		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= 210.0f * Time::DeltaTime();
			tr->SetPosition(pos);

		}
		else if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 210.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 210.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}
}
