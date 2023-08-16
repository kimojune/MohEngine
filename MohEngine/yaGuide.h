#pragma once
#include "yaGungeoneer.h"

namespace ya
{
	class Weapon;
class Guide : public Gungeoneer
{
public:
	Guide();
	virtual ~Guide();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

private:
	Weapon* rust_sidearm;
	Weapon* mBasicSubWeapon;
};
}

