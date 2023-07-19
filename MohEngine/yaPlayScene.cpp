#include "yaPlayScene.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaPlayer.h"
#include "yaPlayerScript.h"
#include "yaMainCamera.h"
#include "hoCursor.h"
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
using namespace ho;
extern ya::Application application;


namespace ya
{

	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		float width = application.GetWidth() ;
		float height = application.GetHeight() ;

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Companions, true);

		Player* player = new Player();
		player->Intialize();
		AddGameObject(eLayerType::Player, player);
		Collider2D* cd = player->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -10.0f));
		cd->SetSize(Vector2(0.6f, 0.6f));
		cd->SetType(eColliderType::Rect);

		MainCamera* camera = new MainCamera();
		Camera* maincam = camera->GetComponent<Camera>();
		camera->SetTarget(player);
		ya::renderer::mainCamera = maincam;

		UICamera* uicamera = new UICamera();

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

		//camera->SetTarget(player);
		Cursor* cursor = new Cursor(uicamera);


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
		const std::wstring& path = { L"..\\Resources\\Tile\\1234" };
		TilePalatte::Load(path);
	}
	void PlayScene::OnExit()
	{
	}
}