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
				pos.z += 500.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			else if (Input::GetKey(eKeyCode::S))
			{
				pos.z -= 500.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			else if (Input::GetKey(eKeyCode::A))
			{
				pos.x -= 500.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			else if (Input::GetKey(eKeyCode::D))
			{
				pos.x += 500.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			else if (Input::GetKey(eKeyCode::Q))
			{
				pos.y -= 500.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			else if (Input::GetKey(eKeyCode::E))
			{
				pos.y += 500.0f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
		}
		else
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 wCursorPos = Input::GetClientMousePos(eCameraType::Main);
			Vector3 targetPos = mTarget->GetComponent<Transform>()->GetPosition();

			Vector3 ConvertPos = Vector3::Zero;
			ConvertPos.x = (wCursorPos.x - targetPos.x) / 3.0f + targetPos.x ;
			ConvertPos.y = (wCursorPos.y - targetPos.y) / 3.0f + targetPos.y ;
			ConvertPos.z = tr->GetPosition().z;

			tr->SetPosition(ConvertPos);
		}

	}
}