#include "yaWeapon.h"
#include "yaWeaponScript.h"
#include "yaMeshRenderer.h"
#include "yaObject.h"
#include "yaSceneManager.h"
#include "yaProjectile.h"
#include "yaPlayScene.h"

namespace ya
{
	Weapon::Weapon()
		: mMesh(NULL)
		, mMaterial(nullptr)
		, mInfo{}
		, mMuzzlePos(Vector3::Zero)
		, isFlip(false)
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
		MeshRenderer* mr = GetComponent<MeshRenderer>();
		
		mScript->SetAttack();
		Vector3 handPos = tr->GetParent()->GetCaculatePos();
		Vector3 handRotation = tr->GetParent()->GetRotation();

		float mRadian = handRotation.z;
		float mLength = sqrtf(mr->GetWidth() * mr->GetWidth() + mr->GetHeight() * mr->GetHeight());
		
		mMuzzlePos = Vector3((handPos.x + mLength * cos(mRadian))
			, (handPos.y + mLength * sin(mRadian)), -5.0f);

		Vector2 direction =
			SceneManager::GetActiveScene()->GetCursorDirectionVector(eCameraType::Main, this);
		//Vector3 caculatePos = Vector3(handPos.x + direction.x * mLength, handPos.y + direction.y * mLength, -5.0f);
		
		mProjectile->SetPos(mMuzzlePos);
		mProjectile->SetDirection(direction);
	}

	void Weapon::IsFlip(bool flip)
	{
		Transform* tr = GetComponent<Transform>();
		MeshRenderer* mr = GetComponent<MeshRenderer>();
		isFlip = flip;

		if (isFlip)
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