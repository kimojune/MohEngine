#include "yaPlayerHand.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaWeapon.h"
#include "yaGungeoneer.h"
#include "yaSceneManager.h"

namespace ya
{
	PlayerHand::PlayerHand()
	{
	}
	PlayerHand::~PlayerHand()
	{
	}
	void PlayerHand::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		mr->SetMaterial(Resources::Find<Material>((L"guide_hand_001_material")));
		
		tr->SetScale(mr->GetWidth(), mr->GetHeight(), 1.0f);
		tr->SetPosition(8.0f, -8.0f, 0.0f);
		
		mActiveWeapon = mWeapons[0];
		Transform* wptr = mActiveWeapon->GetComponent<Transform>();
		wptr->SetParent(tr);
		GameObject::Initialize();
	}
	void PlayerHand::Update()
	{
		Transform* tr = GetComponent<Transform>();

		Vector2 vDirection = SceneManager::GetActiveScene()->GetCursorDirectionVector(eCameraType::Main,tr->GetParent()->GetOwner());
		float radian = atan2f(vDirection.y, vDirection.x);
		float degree = radian * 180 / PI;
		tr->SetRotation(0.0f, 0.0f, radian);

		if (-90.0f < degree && 90.0f >= degree)
		{
			tr->SetPosition(8.0f, -8.0f, 0.0f);
			isFlip = false;
		}
		else
		{
			tr->SetPosition(-8.0f, -8.0f, 0.0f);
			isFlip = true;
		}

		if (prevFlip != isFlip && mActiveWeapon)
			mActiveWeapon->IsFlip(isFlip);

		prevFlip = isFlip;

		GameObject::Update();
	}
	void PlayerHand::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void PlayerHand::Render()
	{
		GameObject::Render();
	}
	void PlayerHand::SetAttack()
	{
		mActiveWeapon->SetAttack();
	}
}