#include "yaPlayer.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaCameraScript.h"

namespace ya
{
	Player::Player()
	{
	}
	Player::~Player()
	{
	}
	void Player::Intialize()
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		mr->SetMaterial(Resources::Find<Material>((L"SpriteMaterial")));
		//player->AddComponent<CameraScript>();
		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	
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