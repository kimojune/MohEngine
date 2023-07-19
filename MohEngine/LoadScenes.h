#pragma once
#include "..\Engine_SOURCE\yaSceneManager.h"
#include "yaPlayScene.h"
#include "yaTitleScene.h"
#include "yaToolScene.h"
#include "yaLobbyScene.h"
#include "yaInventoryScene.h"





//#include "..\YamYamEngine\\yaPlayScene.h"
//#include "yaSceneManager.h"
namespace ya
{
	void InitializeScenes()
	{
		//PlayScene* playScene = new PlayScene();
		SceneManager::CreateScene<InventoryScene>(L"InventoryScene");
		SceneManager::CreateScene<ToolScene>(L"ToolScene");
		SceneManager::CreateScene<LobbyScene>(L"LobbyScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
	}
}