#pragma once
#include "yaGameObject.h"
namespace ya
{
class WorldCursor : public GameObject
{
public:
	WorldCursor();
	~WorldCursor();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;


private:
	Vector3 mPos;
};


}
