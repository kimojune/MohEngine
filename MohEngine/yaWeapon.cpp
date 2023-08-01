#include "yaWeapon.h"
#include "yaWeaponScript.h"
namespace ya
{
	Weapon::Weapon()
		: mMesh(NULL)
		, mMaterial(nullptr)
		, mInfo{}
	{
	}
	Weapon::~Weapon()
	{
	}
	void Weapon::Initialize()
	{
		WeaponScript* script = AddComponent<WeaponScript>();
		script->SetWeaponInfo(mInfo);
		script->Initialize();

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
}