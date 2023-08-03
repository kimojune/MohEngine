#include "yaRust_Sidearm.h"
#include "yaMeshRenderer.h"
#include "yaTransform.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaAnimator.h"
namespace ya
{
	Rust_Sidearm::Rust_Sidearm()
		: mInfo{}
		, mMesh(Resources::Find<Mesh>((L"RectMesh")))
		, mMaterial(Resources::Find<Material>((L"Rust_Sidearm_idle_001_material")))
	{
		SetName(L"Rust_Sidearm");
		Transform* tr = GetComponent<Transform>();

		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(mMesh);
		mr->SetMaterial(mMaterial);
		Vector2 scale = mMaterial->GetSize();
		tr->SetScale(scale.x , scale.y, 1.0f);
		//tr->SetScale(scale.x * 2.0f, scale.y * 2.0f, 1.0f);
		tr->SetPosition(0.0f, 0.0f, -5.0f);

		mInfo.type = eWeaponType::Semiautomatic;
		mInfo.quality = eQuality::None;
		mInfo.maxAmmo = 0;
		mInfo.magazineSize = 6;
		mInfo.reloadTime = 1.2f;
		mInfo.damage = 6;
		mInfo.fireRate_Manual = 0.2;
		mInfo.fireRate_Automatic = 0.25;
		mInfo.shootSpeed = 16.0f;
		mInfo.range = 16.0f;
		mInfo.force = 10.0f;
		mInfo.spreadDegree = 7.0f;
		mInfo.price = 0;
		
		Weapon::SetInfo(mInfo);

	}
	Rust_Sidearm::~Rust_Sidearm()
	{
	}
	void Rust_Sidearm::Initialize()
	{
		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Weapon\\basic\\idle", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Weapon\\basic\\reload", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Texture\\Charactor\\The Hunter\\Weapon\\basic\\shoot", 0.15f);
		at->CreateAnimations(L"..\\Resources\\Test", 0.15f);

		Weapon::SetInfo(mInfo);

		//Collider2D* cd = AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(1.0f, 1.0f));
		//cd->SetType(eColliderType::Rect);

		Weapon::Initialize();
	}
	void Rust_Sidearm::Update()
	{

		Weapon::Update();
	}
	void Rust_Sidearm::LateUpdate()
	{

		Weapon::LateUpdate();
	}
	void Rust_Sidearm::Render()
	{

		Weapon::Render();
	}
}