#include "yaRust_Sidearm.h"
#include "yaMeshRenderer.h"
#include "yaTransform.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaProjectile.h"
namespace ya
{
	Rust_Sidearm::Rust_Sidearm()

	{
		SetName(L"Rust_Sidearm");
		Transform* tr = GetComponent<Transform>();

		mMesh = Resources::Find<Mesh>((L"RectMesh"));
		mMaterial = Resources::Find<Material>((L"Rust_Sidearm_idle_001_material"));

		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(mMesh);
		mr->SetMaterial(mMaterial);
		tr->SetScale(mr->GetWidth(), mr->GetHeight(), 1.0f);

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
		

		MeshRenderer* ptmr = mProjectile->AddComponent<MeshRenderer>();
		Transform* pttr = mProjectile->GetComponent<Transform>();
		ptmr->SetMesh(mMesh);
		std::shared_ptr<Material> ptmater = Resources::Find<Material>((L"rusty_sidearm_projectile_alt_001_material"));
		ptmr->SetMaterial(ptmater);
		pttr->SetScale(ptmater.get()->GetWidth(), ptmater.get()->GetHeight(), 1.0f);
		pttr->SetPosition(Vector3(0.0f, 0.0f, 1.0f));
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