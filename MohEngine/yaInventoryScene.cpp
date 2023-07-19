#include "yaInventoryScene.h"
#include "yaUI.h"
#include "yaUICamera.h"
#include "hoCursor.h"
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

		ho::Cursor* cursor = new ho::Cursor(uicamera);
		

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