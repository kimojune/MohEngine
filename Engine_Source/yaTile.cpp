#include "yaTile.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"

namespace ya
{
	Tile::Tile()
		:mAtlas(nullptr)
		, mIndex(-1)
		, mX(-1)
		, mY(-1)
	{
		SetName(L"Tile");
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector3(512.0f, 512.0f, -10.0f));
	}
	Tile::Tile(Vector2 pos)
		:mAtlas(nullptr)
		, mIndex(-1)
		, mX(-1)
		, mY(-1)
	{
		SetName(L"Tile");
	}
	Tile::~Tile()
	{
	}
	void Tile::InitializeTile(std::shared_ptr<Image> atlas, int index)
	{
		mIndex = index;
		if (atlas == nullptr || index < 0)
			return;

		mAtlas = atlas;
		SetIndex(index);

		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"tile_material"));
		//GameObject::Initialize();
	}

	void Tile::SetIndex(int index)
	{
		int maxCol = mAtlas->GetWidth() / TILE_SIZE_X;
		int maxRow = mAtlas->GetHeight() / TILE_SIZE_Y;

		mY = index / maxCol;
		mX = index % maxRow;
	}
	void Tile::Update()
	{


		GameObject::Update();
	}
	void Tile::Render()
	{
		GameObject::Render();
	}

	void Tile::OnCollisionEnter(Collider* other)
	{
		//GameObject* obj = other->GetOwner();

		//Rigidbody* rb = obj->GetComponent<Rigidbody>();

		//if (rb == nullptr)
		//{
		//	return;
		//}

		//rb->SetGround(true);


		//Collider* objCol = obj->GetComponent<Collider>();
		//Vector2 objPos = objCol->GetPos();

		//Collider* groundCol = this->GetComponent<Collider>();
		//Vector2 groundPos = groundCol->GetPos();

		//float fLen = fabs(objPos.y - groundPos.y);


		//float fSize = (objCol->GetSize().y / 2.0f) + (groundCol->GetSize().y / 2.0f);

		//if (fLen < fSize)
		//{
		//	Transform* objTr = obj->GetComponent<Transform>();
		//	Transform* grTr = this->GetComponent<Transform>();

		//	Vector2 objPos = objTr->GetPos();
		//	Vector2 grPos = grTr->GetPos();

		//	objPos.y -= (fSize - fLen) - 1.0f;
		//	objTr->SetPos(objPos);
		//}
	}

	void Tile::OnCollisionStay(Collider* other)
	{
	}

	void Tile::OnCollisionExit(Collider* other)
	{
		//GameObject* obj = other->GetOwner();

		//Rigidbody* rb = obj->GetComponent<Rigidbody>();
		//if (rb == nullptr)
		//	return;

		//rb->SetGround(false);
	}


}