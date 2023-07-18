#pragma once
#include "..\Engine_SOURCE\yaSceneManager.h"
#include "yaPlayScene.h"
#include "yaTitleScene.h"
#include "yaToolScene.h"





//#include "..\YamYamEngine\\yaPlayScene.h"
//#include "yaSceneManager.h"
namespace ya
{
	void InitializeScenes()
	{
		//PlayScene* playScene = new PlayScene();
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<ToolScene>(L"ToolScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
	}
}