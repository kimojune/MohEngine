#pragma once
#include "yaGameObject.h"

using namespace ya::math;
using namespace ya;

namespace ho
{
class Cursor : public ya::GameObject
{
public:
	Cursor();
	~Cursor();

	virtual void Intialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

private:
	Vector3 mPos;
};
}

