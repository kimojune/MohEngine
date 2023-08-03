#include "yaWeapon.h"
#include "yaWeaponScript.h"
#include "yaMeshRenderer.h"
#include "yaObject.h"
#include "yaSceneManager.h"
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
		Transform* tr = GetComponent<Transform>();
		MeshRenderer* mr = GetComponent<MeshRenderer>();
		Vector2 mPosition = mr->GetSize() / 2;

		tr->SetPosition(mPosition.x, mPosition.y, -5.0f);

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

	void Weapon::IsFlip(bool flip)
	{
		Transform* tr = GetComponent<Transform>();
		MeshRenderer* mr = GetComponent<MeshRenderer>();
		Vector2 mPosition = mr->GetSize() / 2;
		
		if (flip)
		{
			tr->SetPosition(mPosition.x, -mPosition.y, -5.0f);
			mScript->SetFlip(eFlipType::Y);
			mScript->SetPlayed(false);
		}

		else
		{
			tr->SetPosition(mPosition.x, mPosition.y, -5.0f);
			mScript->SetFlip(eFlipType::None);
			mScript->SetPlayed(false);
		}
	}
}