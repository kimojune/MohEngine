#pragma once
#include "yaScript.h"


namespace ya
{
	class ProjectileScript : public Script
	{
	public:
		ProjectileScript();
		~ProjectileScript();

		virtual void Initialize() override;
		virtual void Update() override;

		void SetDirection(Vector2 vector) { mDirection = vector; }

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		Vector2 mDirection;
	};
}
