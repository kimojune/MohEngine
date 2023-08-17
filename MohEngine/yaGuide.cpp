#include "yaGuide.h"
#include "yaAnimator.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaRust_Sidearm.h"
#include "yaObject.h"
#include "yaPlayerHand.h"
namespace ya
{
	Guide::Guide()
	{
		SetName(L"Guide");
	}
	Guide::~Guide()
	{
	}
	void Guide::Initialize()
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		mr->SetMaterial(Resources::Find<Material>((L"guide_idle_front_001_material")));
		//player->AddComponent<CameraScript>();
		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, -5.0f));
		//Vector2 scale = mr->GetSize();
		tr->SetScale(26.0f, 31.0f, 1.0f);

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

		mHand = object::Instantiate<PlayerHand>(eLayerType::Player);
		
		rust_sidearm = new Rust_Sidearm;
		rust_sidearm->Initialize();
		
		mHand->mWeapons.push_back(rust_sidearm);
		
		Gungeoneer::Initialize();
	}
	void Guide::Update()
	{
		Gungeoneer::Update();
	}
	void Guide::LateUpdate()
	{
		Gungeoneer::LateUpdate();
	}
	void Guide::Render()
	{
		Gungeoneer::Render();
	}
}