#pragma once
#include "yaScript.h"

namespace ya
{
	class PlayerHand;
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

		virtual void Initialize() override;
		virtual void Update() override;

		void Idle();
		void Run();
		void Dodge();
		void PitFall();
		void Death();
		
		void SetHand(PlayerHand* hand) { mHand = hand; }

		void PlayAnimationDir(const std::wstring& name, eDirection direction, bool loop);
		void StartDodge();
		void CompleteDodge();

	

	private:
		ePlayerState mPlayerState;
		eDirection mDirection;
		eDirection mInputDirection;
		
		ePlayerState mPrevState;
		eDirection mPrevDirection;
		
		PlayerHand* mHand;

		Vector3 mPos;
		float cursorDegree;

		bool mbPlayed = false;
		bool invincible = false;
		bool animationLoop = true;

		float mSpeed;
		float mStretchSpeed;
		float diagonalRatio;
		float mTime;

	};
}
