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
	BackGround::BackGround(Vector3 pos, Vector3 scale)
		:mMesh(Resources::Find<Mesh>((L"RectMesh")))
		, mMaterial(Resources::Find<Material>((L"MagentaTexture_material")))
		, mPositon(pos)
		, mScale(scale)
	{
		
	}
	BackGround::~BackGround()
	{
	}
	void BackGround::Intialize()
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(mMesh);
		mr->SetMaterial(mMaterial);
		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(mPositon);
		tr->SetScale(mScale);
		
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::BG, this);


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