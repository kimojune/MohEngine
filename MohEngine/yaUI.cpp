#include "yaUI.h"
#include "yaResources.h"
#include "yaMeshRenderer.h"
#include "yaTransform.h"
#include "yaSceneManager.h"

namespace ya
{
	UI::UI(const std::wstring& materialname)
		: mMesh(Resources::Find<Mesh>((L"RectMesh")))
		, mMaterial(Resources::Find<Material>((L"MagentaTexture_material")))
		, mPosition(Vector3::Zero)
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mMaterial = Resources::Find<Material>(materialname);
		mr->SetMesh(mMesh);
		mr->SetMaterial(mMaterial);

		Vector2 scale = mr->GetSize();
		mScale = Vector3(scale.x, scale.y, 1.0f);

		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(mPosition);
		tr->SetScale(mScale);

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);
	}
	UI::UI(Vector3 pos, const std::wstring& materialname)
		:mMesh(Resources::Find<Mesh>((L"RectMesh")))
		, mMaterial(Resources::Find<Material>((L"MagentaTexture_material")))
		, mPosition(pos)
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mMaterial = Resources::Find<Material>(materialname);
		mr->SetMesh(mMesh);
		mr->SetMaterial(mMaterial);

		Vector2 scale = mr->GetSize();
		mScale = Vector3(scale.x, scale.y, 1.0f);

		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(mPosition);
		tr->SetScale(mScale);

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);
	}
	UI::UI(GameObject* obj, Vector3 pos, const std::wstring& materialname)
		:mMesh(Resources::Find<Mesh>((L"RectMesh")))
		, mMaterial(Resources::Find<Material>((L"MagentaTexture_material")))
		, mPosition(pos)
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mMaterial = Resources::Find<Material>(materialname);
		mr->SetMesh(mMesh);
		mr->SetMaterial(mMaterial);

		Vector2 scale = mr->GetSize();
		mScale = Vector3(scale.x, scale.y, 1.0f);
		//mScale = Vector3(1.f, 1.f, 1.f);

		Transform* tr = GetComponent<Transform>();
		tr->SetParent(obj->GetComponent<Transform>());
		tr->SetPosition(mPosition);
		tr->SetScale(mScale);

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);
	}
	UI::~UI()
	{
	}
	void UI::Initialize()
	{
	}
	void UI::Update()
	{
		GameObject::Update();
	}
	void UI::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void UI::Render()
	{
		GameObject::Render();
	}
	void UI::SetPosition(Vector3 pos)
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(mPosition);
	}
	void UI::SetScale(Vector3 scale)
	{
		Transform* tr = GetComponent<Transform>();
		mScale = scale;
		tr->SetScale(mScale);
	}
}
