#include "yaPlayerHand.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaWeapon.h"
#include "yaPlayer.h"

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
		Vector2 scale = mr->GetSize();
		tr->SetScale(scale.x, scale.y, 1.0f);
		tr->SetPosition(8.0f, -8.0f, 0.0f);

		GameObject::Initialize();
	}
	void PlayerHand::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector3 mplayerPos = tr->GetParent()->GetPosition();

		Vector2 playerPos = Vector2(mplayerPos.x, mplayerPos.y);
		Vector2 cursorPos = Input::GetClientMousePos(eCameraType::Main);

		Vector2 vDirection = cursorPos - playerPos;
		vDirection.Normalize();

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

		Player* player = (Player*)tr->GetParent()->GetOwner();

		mWeapon = player->GetActiveWeapon();
		Transform* weapontr = mWeapon->GetComponent<Transform>();

		weapontr->SetParent(tr);


		if (prevFlip != isFlip)
			mWeapon->IsFlip(isFlip);

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
	}
}