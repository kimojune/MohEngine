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
		mInfo.Scale = 0.01f;
		mInfo.x = 0;
		mInfo.y = 0;
		
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
		
		ya::renderer::Setpos(mInfo.x, mInfo.y);
	}
	void Player::LateUpdate()
	{
	}
	void Player::Render()
	{
		GameObject::Render();
	}
}
