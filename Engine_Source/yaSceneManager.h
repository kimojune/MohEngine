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

	static Scene* GetActiveScene() { return mActiveScene; }
	static Scene* LoadScene(std::wstring name);

	static std::map<std::wstring, Scene*> mScenes;
private:
	static Scene* mActiveScene;
};

}
