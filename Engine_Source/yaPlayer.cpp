#include "yaPlayer.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaRenderer.h"

namespace ya
{
	Player::Player()
	{
		Entity::SetName(L"Player");
	}
	Player::~Player()
	{
	}
	void Player::Intialize()
	{
		mInfo = GetInfo();
		mInfo.Scale = 0.03f;
		mInfo.x = 0;
		mInfo.y = 0;
		mInfo.mColor = Vector4{ 1.0f, 0.0f, 0.0f, 1.0f };

		SetInfo(mInfo);
		GameObject::Intialize();

	}
	void Player::Update()
	{
		mInfo = GetInfo();
		if (Input::GetKey(eKeyCode::UP))
			mInfo.y += 0.3f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::DOWN))
			mInfo.y -= 0.3f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::LEFT))
			mInfo.x -= 0.3f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::RIGHT))
			mInfo.x += 0.3f * Time::DeltaTime();

		SetInfo(mInfo);

		GameObject::Update();
	}
	void Player::LateUpdate()
	{
	}
	void Player::Render()
	{

		GameObject::Render();
	}
}
