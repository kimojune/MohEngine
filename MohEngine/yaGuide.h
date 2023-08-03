#pragma once
#include "yaPlayer.h"

namespace ya
{
	class Weapon;
class Guide : public Player
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

