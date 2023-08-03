#include "yaPlayScene.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaGuide.h"
#include "yaMainCamera.h"
#include "yaCursor.h"
#include "yaUICamera.h"
#include "yaApplication.h"
#include "yaUI.h"
#include "yaGridScript.h"
#include "yaCollider2D.h"
#include "yaRenderer.h"
#include "yaDog.h"
#include "yaObject.h"
#include "yaCollisionManager.h"
#include "yaInput.h"
#include "yaTilePalatte.h"
#include "yaLight.h"

using namespace ya;
extern ya::Application application;


namespace ya
{
	PlayScene::PlayScene()
		:mMainCamera(nullptr)
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Companions, true);

		Guide* Hunter = object::Instantiate<Guide>(eLayerType::Player);
		Hunter->Initialize();
		
		mMainCamera = new MainCamera();
		Camera* maincam = mMainCamera->GetComponent<Camera>();
		mMainCamera->SetTarget(Hunter);
		
		float width = application.GetWidth() ;
		float height = application.GetHeight() ;

		UICamera* uicamera = new UICamera();
		Camera* uicam = uicamera->GetComponent<Camera>();

		width *= uicam->GetSize();
		height *= uicam->GetSize();

		//{
		//GameObject* light = new GameObject();
		//light->SetName(L"Smile");
		//AddGameObject(eLayerType::Light, light);
		//Light* lightComp = light->AddComponent<Light>();
		//lightComp->SetType(eLightType::Directional);
		//lightComp->SetColor(Vector4(1.0f, 0.0f, 1.0f, 1.0f));
		//}
		//{
		//GameObject* light = new GameObject();
		//light->SetName(L"Smile");
		//AddGameObject(eLayerType::Light, light);
		//Light* lightComp = light->AddComponent<Light>();
		//lightComp->SetType(eLightType::Point);
		//lightComp->SetColor(Vector4(1.0f, 1.0f, 1.0f, 1.0f));
		//lightComp->SetRadius(100.0f);
		//
		//}



		UI* heart = new UI(Vector3(-width/2 + UI_SIZE, height/2 - UI_SIZE,-6.0f), (L"Heart_material"));
		UI* key = new UI(heart, Vector3(0.0f , -UI_SIZE, -3.0f), (L"ui_key_material"));
		UI* ui_coin = new UI(heart, Vector3(UI_SIZE * 2, -UI_SIZE, -3.0f), (L"ui_coin_material"));
		UI* ui_blank[5] = {};	for (size_t i = 0; i < 5; i++)	{
			ui_blank[i] = new UI(heart, Vector3(0.0f + (UI_SIZE * i), -UI_SIZE * 2, -3.0f), (L"ui_blank_material"));}
		UI* BulletCount = new UI(heart, Vector3(width - UI_SIZE * 2, - height + UI_SIZE * 2, 0.0f), (L"Bullet_count_bottom_material"));
		
		UI* EmeptyBullet[6] = {};
		for (size_t i = 0; i < 6; i++)
		{
			EmeptyBullet[i]
				= new UI(BulletCount
					, Vector3(0.0f, 10.0f + (10.0f * i), -3.0f)
					, (L"Emepty_Bullet_01_material"));
		}
		UI* Bullet[6] = {};
		for (size_t i = 0; i < 5; i++)
		{
			Bullet[i]
				= new UI(BulletCount
					, Vector3(0.0f, 10.0f + (10.0f * i), -3.0f)
					, (L"Bullet_type_01_material"));
		}

		//camera->SetTarget(Hunter);
		Cursor* cursor = new Cursor;


	}
	void PlayScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"ToolScene");
		}
		if (Input::GetKeyDown(eKeyCode::I))
		{
			SceneManager::LoadScene(L"InventoryScene");
		}

		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render()
	{
		Scene::Render();
	}
	void PlayScene::OnEnter()
	{
		mMainCamera->SetSize(0.25f);
	}
	void PlayScene::OnExit()
	{
		//mMainCamera->SetSize(1.0f);
	}
	float PlayScene::GetCameraSize()
	{
		return mMainCamera->GetSize();
	}
}