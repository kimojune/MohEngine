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
		,mPositon(Vector3::Zero)
		,mScale(Vector3::One)
	{
	}
	BackGround::BackGround(Vector3 pos, const std::wstring& materialname)
		:mMesh(Resources::Find<Mesh>((L"RectMesh")))
		, mMaterial(Resources::Find<Material>((L"MagentaTexture_material")))
		, mPositon(pos)
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mMaterial = Resources::Find<Material>(materialname);
		mr->SetMesh(mMesh);
		mr->SetMaterial(mMaterial);

		Vector2 scale = mr->GetSize();
		mScale = Vector3(scale.x, scale.y, 1.0f);

		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(mPositon);
		tr->SetScale(mScale);

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
}