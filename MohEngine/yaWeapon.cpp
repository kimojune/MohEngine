#include "yaWeapon.h"
#include "yaWeaponScript.h"
#include "yaMeshRenderer.h"
#include "yaObject.h"
#include "yaSceneManager.h"
#include "yaProjectile.h"

namespace ya
{
	Weapon::Weapon()
		: mMesh(NULL)
		, mMaterial(nullptr)
		, mInfo{}
		, mFlip(eFlipType::None)
	{
		mProjectile = object::Instantiate<Projectile>(eLayerType::Projectile);
		mProjectile->Initialize();
	}
	Weapon::~Weapon()
	{
	}
	void Weapon::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		MeshRenderer* mr = GetComponent<MeshRenderer>();

		tr->SetPosition(mr->GetWidth() / 2, mr->GetHeight() / 2,  -5.0f);


		mScript = AddComponent<WeaponScript>();
		mScript->SetWeaponInfo(mInfo);
		mScript->Initialize();

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::Player, this);

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

	void Weapon::SetAttack()
	{
		Transform* tr = GetComponent<Transform>();

		mScript->SetAttack();
		mProjectile->SetPos(Vector3::Zero);
		mProjectile->SetDirection(SceneManager::
			GetActiveScene()->GetCursorDirectionVector(eCameraType::Main, this));
	}

	void Weapon::IsFlip(bool flip)
	{
		Transform* tr = GetComponent<Transform>();
		MeshRenderer* mr = GetComponent<MeshRenderer>();

		if (flip)
		{
			tr->SetPosition(mr->GetWidth() / 2, -1.0f * mr->GetHeight() / 2, -5.0f);
			mScript->SetFlip(eFlipType::Y);
		}

		else
		{
			tr->SetPosition(mr->GetWidth() / 2, mr->GetHeight() / 2, -5.0f);
			mScript->SetFlip(eFlipType::None);
		}
	}
}