#include "yaGameObject.h"
#include "yaRenderer.h"
#include "yaGraphicDevice_Dx11.h"

namespace ya
{
	GameObject::GameObject()
		:mState(eState::Active)
		,y(0)
		,x(0)
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
		// �� ������ ����



	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render()
	{

		//������۷� ��ġ���� ũ������, ����, ������Ʈ ������Ѵ�.
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}
