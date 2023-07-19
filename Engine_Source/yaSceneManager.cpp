#include "yaSceneManager.h"
#include "yaInput.h"

namespace ya
{
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mPrevScene = nullptr;
	std::map<std::wstring, Scene*> SceneManager::mScenes;

	void SceneManager::Initialize()
	{
	}
	void SceneManager::Update()
	{
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
		for (auto& iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}
	Scene* SceneManager::LoadScene(std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter = mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene->OnExit();
		mPrevScene = mActiveScene;
		mActiveScene = iter->second;
		mActiveScene->OnEnter();


		return iter->second;
	}
	void SceneManager::LoadPrevScene()
	{
		if (mPrevScene == nullptr)
			return;

		mActiveScene->OnExit();
		Scene* temp = mActiveScene;
		mActiveScene = mPrevScene;
		mPrevScene = temp;
		mActiveScene->OnEnter();
	}
}
