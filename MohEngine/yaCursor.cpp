#include "yaCursor.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaSceneManager.h"
#include "yaUICamera.h"
#include "yaCamera.h"
#include "yaApplication.h"

extern ya::Application application;

namespace ya
{
	using namespace ya;

	Cursor::Cursor()
		: mPos(Vector3(0.0f, 0.0f, -10.0f))

	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(Vector3::One);

		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"reticle_crosshair_002_material"));

		Vector2 scale = mr->GetSize();
		tr->SetScale(Vector3(scale.x, scale.y, 1.0f));
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);

		SetName(L"Cursor");
	}
	Cursor::~Cursor()
	{
	}
	void Cursor::Intialize()
	{

	}
	void Cursor::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 uiPos = Input::GetClientMousePos(eCameraType::UI);
		
		mPos = Vector3(uiPos.x, uiPos.y, mPos.z);

		tr->SetPosition(mPos);
		
		GameObject::Update();
	}
	void Cursor::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Cursor::Render()
	{
		GameObject::Render();
	}

}