#pragma once
#include "yaScript.h"

namespace ya
{
	class PlayerScript : public Script
 	{
	public:
		enum class ePlayerState
		{
			Idle,
			Run,
			Dodge,
			PitFall,
			Death,
			End,
		};

		virtual void Update() override;

		void Idle();
		void Run();
		void Dodge();
		void PitFall();
		void Death();

		void PlayAnimationDir(const std::wstring& name, eDirection direction, bool loop);

	private:
		ePlayerState mState;
		eDirection mDirection;
		
		ePlayerState mPrevState;
		eDirection mPrevDirection;
		bool mbPlayed;

		Vector3 mPos;
		
	};
}
