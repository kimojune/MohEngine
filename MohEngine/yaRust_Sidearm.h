#pragma once
#include "yaWeapon.h"


namespace ya
{
class Rust_Sidearm : public Weapon
{ 
public:
	Rust_Sidearm();
	virtual ~Rust_Sidearm() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;


private:
	WeaponInfo mInfo;
	std::shared_ptr<Mesh> mMesh;
	std::shared_ptr<Material> mMaterial;
	

	bool bPlayed = false;
};
}

