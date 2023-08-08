#include "yaProjectileScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
namespace ya
{
	ProjectileScript::ProjectileScript()
		:mDirection(Vector2::Zero)
	{
	}
	ProjectileScript::~ProjectileScript()
	{
	}
	void ProjectileScript::Initialize()
	{
	}
	void ProjectileScript::Update()
	{
		float mSpeed = 500.0f;

		Transform* tr = GetOwner()->GetComponent<Transform>();
		if (mDirection != Vector2::Zero)
		{
			Vector3 mPos = tr->GetPosition();
			Vector2 pos = Vector2(mPos.x, mPos.y);

			pos += mDirection * mSpeed * Time::DeltaTime();

			tr->SetPosition(Vector3(pos.x, pos.y, mPos.z));
		}
	}
	void ProjectileScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void ProjectileScript::OnCollisionStay(Collider2D* other)
	{
	}
	void ProjectileScript::OnCollisionExit(Collider2D* other)
	{
	}
}