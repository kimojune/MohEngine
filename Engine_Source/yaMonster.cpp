#include "yaMonster.h"

namespace ya
{
	Monster::Monster()
	{
		Entity::SetName(L"Monster");
	}
	Monster::~Monster()
	{
	}
	void Monster::Intialize()
	{
		mInfo = GetInfo();
		mInfo.Scale = 0.01f;

		float x = (RandomNumder() / 10) * IsNegative();
		float y = (RandomNumder() / 10) * IsNegative();

		mInfo.x = x;
		mInfo.y = y;

		Vector4 vector = { x, y, (RandomNumder() / 10), 1 };
		mInfo.mColor = vector;
		mInfo.Scale = RandomNumder() / 100;
		
		SetInfo(mInfo);

		double angle = degreeToRadian(RandomDegrees());

		mDirection.x = std::cos(angle);
		mDirection.y = std::sin(angle);


	}
	void Monster::Update()
	{
		mInfo = GetInfo();

		if(-1<= mInfo.x&& mInfo.x <=1)
			mInfo.x += mDirection.x * Time::DeltaTime() / 10;

		else
		{
			float mValue = sqrt(mDirection.x * mDirection.x + mDirection.y * mDirection.y);

			Vector2 nomalizeDirection;
			nomalizeDirection.x = mDirection.x / mValue;
			nomalizeDirection.y = mDirection.y / mValue;

			if (mInfo.x <= -1)
			{
				Vector2 Left = { -1.0f,0.0f };


				float dot = nomalizeDirection.x * Left.x + nomalizeDirection.y * Left.y;

				Vector2 reflectVector = nomalizeDirection - (2 * dot * Left);

				mDirection = reflectVector * mValue;
			}

			if (mInfo.x >= 1)
			{
				Vector2 Right = { 1.0f,0.0f };


				float dot = nomalizeDirection.x * Right.x + nomalizeDirection.y * Right.y;

				Vector2 reflectVector = nomalizeDirection - (2 * dot * Right);

				mDirection = reflectVector * mValue;
			}
		}

		if (-1 <= mInfo.y && mInfo.y <= 1)
			mInfo.y += mDirection.y * Time::DeltaTime() / 10;
		else
		{
			float mValue = sqrt(mDirection.x * mDirection.x + mDirection.y * mDirection.y);

			Vector2 nomalizeDirection;
			nomalizeDirection.x = mDirection.x / mValue;
			nomalizeDirection.y = mDirection.y / mValue;

			if (mInfo.y <= -1)
			{
				Vector2 Top = { 1.0f,0.0f };


				float dot = nomalizeDirection.x * Top.x + nomalizeDirection.y * Top.y;

				Vector2 reflectVector = nomalizeDirection - (2 * dot * Top);

				mDirection = reflectVector * mValue;
			}

			if (mInfo.y >= 1)
			{
				Vector2 Bottom = { -1.0f,0.0f };


				float dot = nomalizeDirection.x * Bottom.x + nomalizeDirection.y * Bottom.y;

				Vector2 reflectVector = nomalizeDirection - (2 * dot * Bottom);

				mDirection = reflectVector * mValue;
			}
		}

	 


		

		SetInfo(mInfo);

		GameObject::Update();
	}
	void Monster::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Monster::Render()
	{
		GameObject::Render();
	}
}