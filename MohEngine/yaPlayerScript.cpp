#include "yaPlayerScript.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaGameObject.h"

namespace ya
{
	void PlayerScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		 if (Input::GetKey(eKeyCode::W) &&Input::GetKey(eKeyCode::D))
		{
			pos.x += 140.0f * Time::DeltaTime();
			pos.y += 140.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::W) &&Input::GetKey(eKeyCode::A))
		{
			pos.x -= 140.0f * Time::DeltaTime();
			pos.y += 140.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S) &&Input::GetKey(eKeyCode::D))
		{
			pos.x += 140.0f * Time::DeltaTime();
			pos.y -= 140.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S) &&Input::GetKey(eKeyCode::A))
		{
			pos.x -= 140.0f * Time::DeltaTime();
			pos.y -= 140.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::W))
		{
			pos.y += 200.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= 200.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 200.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 200.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::Q))
		{
			pos.z -= 200.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::E))
		{
			pos.z += 200.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}
}
