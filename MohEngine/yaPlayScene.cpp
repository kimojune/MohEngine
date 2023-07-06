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
#include  "yaGridScript.h"
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

		Player* player = new Player();
		player->Intialize();
		AddGameObject(eLayerType::Player, player);

		MainCamera* camera = new MainCamera();
		UICamera* uicamera = new UICamera();

		UI* heart = new UI(Vector3(-half_width / 4, half_height / 4, 0.0f), (L"Heart_material"));
		UI* key = new UI(heart, Vector3(-16.0f, -16.0f, -3.0f), (L"ui_key_material"));
		UI* ui_coin = new UI(heart, Vector3(16.0f, -16.0f, -3.0f), (L"ui_coin_material"));
		UI* ui_blank[5] = {};	for (size_t i = 0; i < 5; i++)	{
			ui_blank[i] = new UI(heart, Vector3(-16.0f + (16.0f * i), -32.0f, -3.0f), (L"ui_blank_material"));}
		UI* BulletCount = new UI(Vector3(half_width / 4 + 15.0f, -half_height / 4, 0.0f), (L"Bullet_count_bottom_material"));
		UI* Bullet[5] = {}; for (size_t i = 0; i < 5; i++) {
			Bullet[i] = new UI(BulletCount, Vector3(0.0f , 5.0f + (6.0f * i), -3.0f), (L"Bullet_type_01_material"));
		}
		UI* EmeptyBullet = new UI(BulletCount, Vector3(0.0f, 30.0f, -3.0f), (L"Emepty_Bullet_01_material"));
			
		camera->SetTarget(player);
		Cursor* cursor = new Cursor(uicamera);

		GameObject* grid = new GameObject();
		grid->SetName(L"Grid");
		AddGameObject(eLayerType::Grid, grid);
		MeshRenderer* mr = grid->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"GridMaterial"));
		GridScript* gridSc = grid->AddComponent<GridScript>();
		gridSc->SetCamera(uicamera->GetComponent<Camera>());

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