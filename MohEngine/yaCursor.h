#pragma once
#include "yaGameObject.h"
#include "yaUICamera.h"



namespace ya
{
class Cursor : public ya::GameObject
{
public:
	Cursor();
	~Cursor();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	Vector3 GetPos() { return mPos; }
	
private:
	Vector3 mPos;
};
}

