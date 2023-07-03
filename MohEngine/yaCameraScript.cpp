#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{

	void CameraScript::Update()
	{

		if (mTarget == nullptr)
		{

			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();

			if (Input::GetKey(eKeyCode::W))
			{
				pos.z += 50.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			else if (Input::GetKey(eKeyCode::S))
			{
				pos.z -= 50.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			else if (Input::GetKey(eKeyCode::A))
			{
				pos.x -= 50.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			else if (Input::GetKey(eKeyCode::D))
			{
				pos.x += 50.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			else if (Input::GetKey(eKeyCode::Q))
			{
				pos.y -= 50.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			else if (Input::GetKey(eKeyCode::E))
			{
				pos.y += 50.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
		}
		else
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			tr->SetPosition(mTarget->GetComponent<Transform>()->GetPosition() + Vector3(0.0f, 0.0f, -10.0f));
		}

	}
}