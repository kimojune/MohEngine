#include "yaCollider2D.h"
#include "yaGameObject.h"
#include "yaRenderer.h"
namespace ya
{
	UINT Collider2D::mColliderNumber = 0;

	Collider2D::Collider2D()
		: Component(eComponentType::Collider2D)
		, mTransform(nullptr)
		, mSize(Vector2::One)
		, mCenter(Vector2::Zero)
		, mRadius(1)
		, mType(eColliderType::Rect)
	{
		mColliderNumber++;
		mColliderID = mColliderNumber;
	}
	Collider2D::~Collider2D()
	{
	}
	void Collider2D::Initialize()
	{
		mTransform = GetOwner()->GetComponent<Transform>();
	}
	void Collider2D::Update()
	{
	}
	void Collider2D::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();

		Vector3 scale = tr->GetScale();
		scale.x *= mSize.x;
		scale.y *= mSize.y;

		Vector3 pos = tr->GetPosition();
		pos.x += mCenter.x;
		pos.y += mCenter.y;

		mPosition = pos;

		graphics::DebugMesh mesh = {};

		mesh.position = pos;
		mesh.rotation = tr->GetRotation();
		
		switch (mType)
		{
		case ya::enums::eColliderType::Rect:
			mesh.type = eColliderType::Rect;
			mesh.scale = scale;
			break;

		case ya::enums::eColliderType::Circle:
			mesh.type = eColliderType::Circle;

			if (scale.x > scale.y)
			{
				mRadius = scale.y / 2;
				mesh.radius = mRadius;
			}

			else
			{
				mRadius = scale.x / 2;
				mesh.radius = mRadius;
			}
			mesh.scale = Vector3(mRadius * 2, mRadius * 2, mRadius * 2);

			break;
		
		case ya::enums::eColliderType::Sphere:
			break;
		
		case ya::enums::eColliderType::Cube:
			break;
		
		case ya::enums::eColliderType::End:
			break;
		default:
			break;
		}

		renderer::PushDebugMeshAttribute(mesh);
	}
	void Collider2D::Render()
	{
	}
	void Collider2D::OnCollisionEnder(Collider2D* other)
	{
		const std::vector<Script*>& scripts
			= GetOwner()->GetComponents<Script>();
		
		for (Script* script : scripts)
		{
			script->OnCollisionEnter(other);
		}

	}
	void Collider2D::OnCollisionStay(Collider2D* other)
	{
		const std::vector<Script*>& scripts
			= GetOwner()->GetComponents<Script>();

		for (Script* script : scripts)
		{
			script->OnCollisionStay(other);
		}
	}
	void Collider2D::OnCollisionExit(Collider2D* other)
	{
		const std::vector<Script*>& scripts
			= GetOwner()->GetComponents<Script>();

		for (Script* script : scripts)
		{
			script->OnCollisionExit(other);
		}
	}

}