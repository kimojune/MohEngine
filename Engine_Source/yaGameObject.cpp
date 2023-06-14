#include "yaGameObject.h"
#include "yaRenderer.h"
#include "yaGraphicDevice_Dx11.h"
#include "yaInput.h"
#include "yaTime.h"

namespace ya
{
	using namespace graphics;
	static bool seed = false;

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
		
		Vector4 vector = { mInfo.x, mInfo.y, mInfo.Scale, 0.0f };
		ya::renderer::constantBuffer->SetData(&vector);
		ya::renderer::constantBuffer->Bind(eShaderStage::VS);

		Vector4 Color = mInfo.mColor;
		ya::renderer::constantBuffer2->SetData(&Color);
		ya::renderer::constantBuffer2->Bind(eShaderStage::VS);

		
		//상수버퍼로 위치정보 크기정보, 색깔, 업데이트 해줘야한다.
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}

	float GameObject::RandomNumder()
	{

		if (!seed)
		{
			srand(time(0));
			seed = true;
		}

		float fnum = rand() % 10;
	
		return fnum;
	}

	double GameObject::RandomDegrees()
	{
		if (!seed)
		{
			srand(time(0));
			seed = true;
		}	
		double degree = rand() * 361;
		
		return degree;
	}

	double GameObject::degreeToRadian(double degree)
	{
		return degree * PI / 180;
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
