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
	Player::Player()
	{
		SetName(L"Player");

	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		mr->SetMaterial(Resources::Find<Material>((L"guide_idle_front_001_material")));
		//player->AddComponent<CameraScript>();
		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, -5.0f));
		//Vector2 scale = mr->GetSize();
		tr->SetScale(26.0f, 31.0f, 1.0f);

		Collider2D* cd = AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -6.0f));
		cd->SetSize(Vector2(0.6f, 0.6f));
		cd->SetType(eColliderType::Rect);
		
		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\front", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\back", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\back_right", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\front_right", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\front_hand", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\front_hand2", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\front_right_hand", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\idle\\front_right_hand2", 0.15f);
																	  
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\run\\front", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\run\\back", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\run\\back_right", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\run\\front_right", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\run\\front_hand", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\run\\front_hand2", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\run\\front_right_hand", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\run\\front_right_hand2", 0.15f);
																	  
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\dodge\\front", 0.1f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\dodge\\back", 0.1f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\dodge\\back_right", 0.1f);	
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Guide\\dodge\\front_right", 0.1f);

		AddComponent<PlayerScript>();

		hand = object::Instantiate<Playerhand>(eLayerType::Player);
		Transform* handtr = hand->GetComponent<Transform>();
		handtr->SetParent(tr);
		hand->Initialize();
		
		Rust_Sidearm* weapon = object::Instantiate<Rust_Sidearm>(eLayerType::Weapon);
		weapon->Initialize();
		hand->SetWeapon(weapon);
		
		Transform* weapontr = weapon->GetComponent<Transform>();
		weapontr->SetParent(handtr);

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