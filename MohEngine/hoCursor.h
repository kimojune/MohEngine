#pragma once
#include "yaGameObject.h"
#include "yaUICamera.h"

using namespace ya::math;
using namespace ya;


namespace ho
{
class Cursor : public ya::GameObject
{
public:
	Cursor(GameObject* camera);
	~Cursor();

	virtual void Intialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	Vector3 TranslateWorldPos(Vector3 pos);

private:
	Vector3 mPos;
	GameObject* mCamera;
};
}

