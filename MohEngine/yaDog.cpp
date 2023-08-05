#include "yaDog.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
	Dog::Dog()
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		//mr->SetMaterial(Resources::Find<Material>((L"dog_idle_left_001_material")));
		mr->SetMaterial(Resources::Find<Material>((L"SpriteMaterial02")));
	

		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.5f, 0.5f, 0.0f));
		//tr->SetScale(mr->GetWidth(), mr->GetHeight(), -0.3f);
		tr->SetScale(50.f, 50.f, -0.3f);

	}
	Dog::~Dog()
	{
	}
	void Dog::Intialize()
	{

	}
	void Dog::Update()
	{
		GameObject::Update();
	}
	void Dog::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Dog::Render()
	{
		GameObject::Render();
	}
}