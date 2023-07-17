#include "yaPlayer.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaCameraScript.h"
#include "yaPlayerScript.h"

namespace ya
{
	Player::Player()
		:mPixelSize(Vector3(26.0f, 31.0f, 0.0f))
	{
	}
	Player::~Player()
	{
	}
	void Player::Intialize()
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		mr->SetMaterial(Resources::Find<Material>((L"guide_idle_front_001_material")));
		//player->AddComponent<CameraScript>();
		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		tr->SetScale(mPixelSize);

		AddComponent<PlayerScript>();
	
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
}