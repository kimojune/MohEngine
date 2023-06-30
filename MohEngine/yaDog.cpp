#include "yaDog.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
	Dog::Dog()
	{
	}
	Dog::~Dog()
	{
	}
	void Dog::Intialize()
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>((L"RectMesh")));
		mr->SetMaterial(Resources::Find<Material>((L"dog_idle_left_001_material")));

		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.5f, 0.5f, 0.0f));
	}
	void Dog::Update()
	{
	}
	void Dog::LateUpdate()
	{
	}
	void Dog::Render()
	{
	}
}