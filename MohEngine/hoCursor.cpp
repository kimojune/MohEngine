#include "hoCursor.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaSceneManager.h"

namespace ho
{
	Cursor::Cursor()
		:mPos(Vector3(0.0f,0.0f,-20.0f))
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector3(13.0f, 13.0f, 1.0f));
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"reticle_crosshair_002_material"));

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
		Vector2 Pos = ya::Input::GetMousePos() * 100.0f;
		mPos = Vector3(Pos.x, Pos.y, 0.0f);

		Vector3 inversepos = tr->TranslateWorldMatrix(mPos);
		//tr->SetPosition(inversepos);
		
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