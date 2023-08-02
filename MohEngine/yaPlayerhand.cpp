#include "yaPlayerhand.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaWeapon.h"

namespace ya
{
	Playerhand::Playerhand()
	{
	}
	Playerhand::~Playerhand()
	{
	}
	void Playerhand::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		mr->SetMaterial(Resources::Find<Material>((L"guide_hand_001_material")));
		Vector2 scale = mr->GetSize();
		tr->SetScale(scale.x, scale. y, 1.0f);
		tr->SetPosition(8.0f, -8.0f, 0.0f);

		GameObject::Initialize();
	}
	void Playerhand::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector3 mplayerPos = tr->GetParent()->GetPosition();
		

		Vector2 playerPos = Vector2(mplayerPos.x, mplayerPos.y);
		Vector2 cursorPos = Input::GetClientMousePos(eCameraType::Main);

		Vector2 vDirection = cursorPos - playerPos;
		vDirection.Normalize();

		float radian = atan2f(vDirection.y, vDirection.x);
		float degree  = radian * 180 / PI;
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

		mWeapon->IsFlip(isFlip);
		
		GameObject::Update();
	}
	void Playerhand::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Playerhand::Render()
	{
		GameObject::Render();
	}
}