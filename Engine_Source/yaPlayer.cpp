#include "yaPlayer.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaRenderer.h"

namespace ya
{
	Player::Player()
	{
	}
	Player::~Player()
	{
	}
	void Player::Intialize()
	{
		mInfo.Scale = 0.1f;
		mInfo.x = 0;
		mInfo.y = 0;
		mInfo.mColor = Vector4{ 1.0f, 0.0f, 0.0f, 1.0f };
	}
	void Player::Update()
	{
		if (Input::GetKey(eKeyCode::UP))
			mInfo.y += 1 * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::DOWN))
			mInfo.y -= 1 * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::LEFT))
			mInfo.x -= 1 * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::RIGHT))
			mInfo.x += 1 * Time::DeltaTime();
	}
	void Player::LateUpdate()
	{
	}
	void Player::Render()
	{

		GameObject::Render();
	}
}
