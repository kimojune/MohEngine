#pragma once
#include "yaScript.h"

namespace ya
{
	class PlayerScript : public Script
 	{
	public:
		enum class ePlayState
		{
			Idle,
			Move,
			Run,
			Dodge,
			PitFall,
			Death,
			End,
		};

		virtual void Update() override;

		void Idle();
		void Move();
		void Run();
		void Dodge();
		void PitFall();
		void Death();



	private:
		ePlayState mState;
		eDirection mDirection;
	};
}
