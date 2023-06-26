#include "yaSceneManager.h"
#include "yaPlayScene.h"
#include "yaTitleScene.h"
#include "yaInput.h"

namespace ya
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*> SceneManager::mScenes;

	void SceneManager::Initialize()
	{
		TitleScene* titlescene = new TitleScene();
		PlayScene* playScene = new PlayScene();


		mScenes.insert(std::make_pair(L"TitleScene", titlescene));
		mScenes.insert(std::make_pair(L"PlayScene", playScene));

		for (auto iter : mScenes)
		{
			iter.second->Initialize();
		}

		mActiveScene = titlescene;

	}
	void SceneManager::Update()
	{
		if (Input::GetKeyDown(eKeyCode::N))
			mActiveScene = mScenes.find(L"PlayScene")->second;
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render()
	{
		mActiveScene->Render();
	}
	void SceneManager::Release()
	{
		for (auto iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	Scene* SceneManager::LoadScene(std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter = mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene->OnExit();
		mActiveScene = iter->second;
		mActiveScene->OnEnter();


		return iter->second;
	}
}
