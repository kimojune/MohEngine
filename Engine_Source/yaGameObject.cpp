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
		// 공 움직임 구현



	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render()
	{

		//상수버퍼로 위치정보 크기정보, 색깔, 업데이트 해줘야한다.
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}
