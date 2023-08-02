#include "yaWeapon.h"
#include "yaWeaponScript.h"
#include "yaMeshRenderer.h"

namespace ya
{
	Weapon::Weapon()
		: mMesh(NULL)
		, mMaterial(nullptr)
		, mInfo{}
		, mFlip(eFlipType::None)
	{
	}
	Weapon::~Weapon()
	{
	}
	void Weapon::Initialize()
	{
		mScript = AddComponent<WeaponScript>();
		mScript->SetWeaponInfo(mInfo);
		mScript->Initialize();

		GameObject::Initialize();
	}
	void Weapon::Update()
	{
		GameObject::Update();
	}
	void Weapon::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Weapon::Render()
	{
		GameObject::Render();
	}
	void Weapon::IsFlip(bool flip)
	{
		Transform* tr = GetComponent<Transform>();
		MeshRenderer* mr = GetComponent<MeshRenderer>();
		Vector2 mPosition = mr->GetSize() / 2;
		
		if (flip)
		{
			tr->SetPosition(mPosition.x, -mPosition.y, -5.0f);
			mScript->SetFlip(eFlipType::Y);
		}

		else
		{
			tr->SetPosition(mPosition.x, mPosition.y, -5.0f);
			mScript->SetFlip(eFlipType::None);
		}
	}
}