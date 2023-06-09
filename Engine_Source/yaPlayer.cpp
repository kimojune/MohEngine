#include "yaPlayer.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaRenderer.h"

namespace ya
{
	Player::Player()
	{
		Entity::SetName(L"player");
	}
	Player::~Player()
	{
	}
	void Player::Intialize()
	{
		mInfo.Scale = 0.01f;
		mInfo.x = 0;
		mInfo.y = 0;
		mInfo.mColor = Vector4{ 1.0f, 0.0f, 0.0f, 1.0f };

		GameObject::Intialize();

	}
	void Player::Update()
	{
		if (Input::GetKey(eKeyCode::UP))
			mInfo.y += 0.3f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::DOWN))
			mInfo.y -= 0.3f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::LEFT))
			mInfo.x -= 0.3f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::RIGHT))
			mInfo.x += 0.3f * Time::DeltaTime();

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
