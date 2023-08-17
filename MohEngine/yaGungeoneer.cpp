#include "yaGungeoneer.h"
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

	Gungeoneer::Gungeoneer()
	{
		SetName(L"Player");

	}
	Gungeoneer::~Gungeoneer()
	{
	}
	void Gungeoneer::Initialize()
	{
		Transform* tr = GetComponent<Transform>();

		Collider2D* cd = AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -6.0f));
		cd->SetSize(Vector2(0.6f, 0.6f));
		cd->SetType(eColliderType::Rect);
		
		PlayerScript* mScript = AddComponent<PlayerScript>();
		Transform* handtr = mHand->GetComponent<Transform>();
		handtr->SetParent(tr);
		mHand->Initialize();

		mScript->SetHand(mHand);
	}
	void Gungeoneer::Update()
	{
		GameObject::Update();
	}
	void Gungeoneer::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Gungeoneer::Render()
	{
		GameObject::Render();

	}
	void Gungeoneer::SetAttack()
	{
		
	}

}