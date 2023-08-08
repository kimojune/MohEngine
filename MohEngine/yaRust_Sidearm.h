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

};
}

