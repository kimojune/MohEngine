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
		Info info = GetInfo();
		Vector4 vector = { info.x,info.y,0.0f,0.0f };
		ya::renderer::constantBuffer->SetData(&vector);
		ya::renderer::constantBuffer->Bind(eShaderStage::VS);

		//������۷� ��ġ���� ũ������, ����, ������Ʈ ������Ѵ�.
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
	float GameObject::RandomNumder()
	{
		srand(time(0));
		float fnum = rand() % 10;
	
		return fnum;
	}

	int GameObject::IsNegative()
	{
		if ((UINT)RandomNumder() % 2 == 0)
		{
			return 1;
		}

		return -1;
	}

}