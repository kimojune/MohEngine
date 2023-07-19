#pragma once
#include "yaPlayScene.h"

namespace ya 
{
class LobbyScene : public PlayScene
{
public:
	LobbyScene();
	virtual ~LobbyScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
};
	
}

