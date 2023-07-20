#include "yaInventoryScene.h"
#include "yaUI.h"
#include "yaUICamera.h"
#include "yaCursor.h"
#include "yaInput.h"
#include "yaSceneManager.h"
namespace ya
{
	InventoryScene::InventoryScene()
	{
	}
	InventoryScene::~InventoryScene()
	{
	}
	void InventoryScene::Initialize()
	{
		UI* ammonomicon_outro_001 = new UI(L"ammonomicon_outro_001_material");
		UICamera* uicamera = new UICamera();

		ya::Cursor* cursor = new ya::Cursor;
		

		Scene::Initialize();
	}
	void InventoryScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::I))
		{
			SceneManager::LoadPrevScene();
		}

		Scene::Update();
	}
	void InventoryScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void InventoryScene::Render()
	{
		Scene::Render();
	}
	void InventoryScene::Destroy()
	{
		Scene::Destroy();
	}
	void InventoryScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void InventoryScene::OnExit()
	{
		Scene::OnExit();
	}
}