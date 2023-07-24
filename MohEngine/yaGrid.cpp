#include "yaGrid.h"
#include "yaObject.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaGridScript.h"
#include "yaCamera.h"
namespace ya
{
	Grid::Grid()
	{
		SetName(L"Grid");
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"GridMaterial"));
		mScript = AddComponent<GridScript>();
	}
	Grid::~Grid()
	{
	}
	void Grid::Initialize()
	{
	}
	void Grid::Update()
	{
		GameObject::Update();
	}
	void Grid::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Grid::Render()
	{
		GameObject::Render();
	}
}
