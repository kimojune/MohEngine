#pragma once
#include "yaSceneManager.h"
#include "yaPlayScene.h"
#include "yaTitleScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\MohEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\MohEngine.lib")
#endif



//#include "..\YamYamEngine\\yaPlayScene.h"
//#include "yaSceneManager.h"
namespace ya
{
	void InitializeScenes()
	{
		//PlayScene* playScene = new PlayScene();
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
	}
}