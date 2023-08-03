#include "yaPlayer.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaCameraScript.h"
#include "yaPlayerScript.h"
#include "yaAnimator.h"
#include "yaRust_Sidearm.h"
#include "yaObject.h"
#include "yaPlayerhand.h"
#include "yaWeaponScript.h"

namespace ya
{
	static GameObject* mActivePlayer = nullptr;

	Player::Player()
	{
		SetName(L"Player");

	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		Transform* tr = GetComponent<Transform>();

		Collider2D* cd = AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -6.0f));
		cd->SetSize(Vector2(0.6f, 0.6f));
		cd->SetType(eColliderType::Rect);
		
		PlayerScript* mScript = AddComponent<PlayerScript>();

		hand = object::Instantiate<PlayerHand>(eLayerType::Player);
		Transform* handtr = hand->GetComponent<Transform>();
		handtr->SetParent(tr);
		hand->Initialize();

		mActiveWeapon = mWeapons[0];
		//mActiveWeapon->AddComponent<WeaponScript>();
		mScript->SetWeapon(mActiveWeapon);
		//hand->SetWeapon(weapon);
		
		//Transform* weapontr = weapon->GetComponent<Transform>();
		//weapontr->SetParent(handtr);
	}
	void Player::Update()
	{
		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Player::Render()
	{
		GameObject::Render();

	}
	void Player::SetAttack()
	{
		
	}

}