#pragma once
#include "yaScene.h"

namespace ya
{

class SceneManager
{
public:
	static void Initialize();
	static void Update();
	static void LateUpdate();
	static void Render();
	static void Release();
	static void Destroy();

	template <typename T>
	static bool CreateScene(std::wstring name)
	{
		T* scene = new T();

		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter != mScenes.end())
			return false;

		mScenes.insert(std::make_pair(name, scene));
		mActiveScene = scene;
		scene->Initialize();
		return true;
	}
	static Scene* LoadScene(std::wstring name);

	static Scene* GetActiveScene() { return mActiveScene; }

	static std::map<std::wstring, Scene*> mScenes;
private:
	static Scene* mActiveScene;
};

}
