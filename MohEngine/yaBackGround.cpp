#pragma once
#include "yaBackGround.h"
#include "yaResources.h"
#include "yaMeshRenderer.h"
#include "yaTransform.h"
#include "yaSceneManager.h"

namespace ya
{
	BackGround::BackGround()
		:mMesh(Resources::Find<Mesh>((L"RectMesh")))
		,mMaterial(Resources::Find<Material>((L"MagentaTexture_material")))
		,mPosition(Vector3::Zero)
		,mScale(Vector3::One)
	{
	}
	BackGround::BackGround(const std::wstring& materialname)
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
		scene->AddGameObject(eLayerType::BG, this);
	}
	BackGround::BackGround(GameObject* obj, const std::wstring& materialname)
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
		tr->SetParent(obj->GetComponent<Transform>());

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::BG, this);
	}
	BackGround::~BackGround()
	{
	}
	void BackGround::Intialize()
	{

	}
	void BackGround::Update()
	{
		GameObject::Update();
	}
	void BackGround::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void BackGround::Render()
	{
		GameObject::Render();
	}
	void BackGround::SetPosition(Vector3 pos)
	{
		Transform* tr = GetComponent<Transform>();
		mPosition = pos;
		tr->SetPosition(mPosition);
	}
	void BackGround::SetScale(Vector3 scale)
	{
		Transform* tr = GetComponent<Transform>();
		mScale = scale;
		tr->SetScale(mScale);
	}
}