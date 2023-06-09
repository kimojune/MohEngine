#include "yaGameObject.h"
#include "yaRenderer.h"
#include "yaGraphicDevice_Dx11.h"
#include "yaInput.h"
#include "yaTime.h"

namespace ya
{
	using namespace graphics;

	GameObject::GameObject()
		:mState(eState::Active)
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

		//상수버퍼로 위치정보 크기정보, 색깔, 업데이트 해줘야한다.
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}
