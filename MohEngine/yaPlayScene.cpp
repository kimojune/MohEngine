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
		float half_width = application.GetWidth() / 2;
		float half_height = application.GetHeight() / 2;

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Companions, true);

		Player* player = new Player();
		player->Intialize();
		AddGameObject(eLayerType::Player, player);
		Collider2D* cd = player->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -10.0f));
		cd->SetSize(Vector2(0.6f, 0.6f));
		cd->SetType(eColliderType::Rect);
		
		Dog* dog = object::Instantiate<Dog>(eLayerType::Companions);
		Collider2D* dogcd = dog->AddComponent<Collider2D>();
		Transform* tr = dog->GetComponent<Transform>();
		float degree = PI / 8.0f;


		tr->SetRotation(Vector3(0.0f, 0.0f, degree));
		dogcd->SetCenter(Vector2(0.0f, 0.0f));
		dogcd->SetType(eColliderType::Rect);

		MainCamera* camera = new MainCamera();
		Camera* maincam = camera->GetComponent<Camera>();
		camera->SetTarget(player);
		ya::renderer::mainCamera = maincam;

		UICamera* uicamera = new UICamera();

		UI* heart = new UI(Vector3(-half_width/2 + 32.0f, half_height/2 - 32.0f,-6.0f), (L"Heart_material"));
		UI* key = new UI(heart, Vector3(0.0f , -32.0f, -3.0f), (L"ui_key_material"));
		UI* ui_coin = new UI(heart, Vector3(64.0f, -32.0f, -3.0f), (L"ui_coin_material"));
		UI* ui_blank[5] = {};	for (size_t i = 0; i < 5; i++)	{
			ui_blank[i] = new UI(heart, Vector3(0.0f + (32.0f * i), -64.0f, -3.0f), (L"ui_blank_material"));}
		UI* BulletCount = new UI(heart, Vector3(half_width - 64.0f, - half_height + 64.0f, 0.0f), (L"Bullet_count_bottom_material"));
		
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



		//GameObject* grid = new GameObject();
		//grid->SetName(L"Grid");
		//AddGameObject(eLayerType::Grid, grid);
		//MeshRenderer* mr = grid->AddComponent<MeshRenderer>();
		//mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//mr->SetMaterial(Resources::Find<Material>(L"GridMaterial"));
		//GridScript* gridSc = grid->AddComponent<GridScript>();
		//gridSc->SetCamera(camera->GetComponent<Camera>());

	}
	void PlayScene::Update()
	{
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
}