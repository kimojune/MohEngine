#include "yaProjectile.h"
#include "yaProjectileScript.h"
namespace ya
{
	Projectile::Projectile()
		: directionVector(Vector2::Zero)
		, mPos(Vector3::Zero)
		, mTexture(nullptr)
	{
	}
	Projectile::~Projectile()
	{
	}
	void Projectile::Initialize()
	{
		mScript = AddComponent<ProjectileScript>();
		GameObject::Initialize();
	}
	void Projectile::Update()
	{
		Vector2 vector = directionVector;

		Transform* tr = GetComponent<Transform>();
		GameObject::Update();
	}
	void Projectile::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Projectile::Render()
	{
		GameObject::Render();
	}
	void Projectile::SetDirection(Vector2 vector)
	{
		mScript->SetDirection(vector);
	}
	void Projectile::SetPos(Vector3 pos)
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(pos);
		mScript->SetDirection(Vector2::Zero);

	}
}