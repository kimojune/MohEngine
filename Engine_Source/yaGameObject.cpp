#include "yaGameObject.h"
#include "yaRenderer.h"
#include "yaGraphicDevice_Dx11.h"

namespace ya
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Intialize()
	{

	}
	void GameObject::Update()
	{
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render()
	{
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}
