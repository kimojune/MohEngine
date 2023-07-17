#include "yaTile.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaImage.h"
#include "yaRenderer.h"

namespace ya
{
	Tile::Tile()
		:mAtlas(nullptr)
		, mIndex(-1)
		, mX(-1)
		, mY(-1)
		,maxCol(0)
		,maxRow(0)
	{
		
	}
	Tile::Tile(Vector2 pos)
		:mAtlas(nullptr)
		, mIndex(-1)
		, mX(-1)
		, mY(-1)
		, maxCol(0)
		, maxRow(0)
	{
	}
	Tile::~Tile()
	{
	}
	void Tile::InitializeTile(std::shared_ptr<Image> atlas, int index)
	{
		mIndex = index;
		if (atlas == nullptr || index < 0)
			return;
		SetName(L"Tile");

		mAtlas = atlas;
		SetIndex(index);
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector3(TILE_SIZE_X , TILE_SIZE_Y, -10.0f));
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"TileMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"tile_material"));

		//GameObject::Initialize();
	}

	void Tile::SetIndex(int index)
	{
		maxRow = mAtlas->GetWidth() / TILE_SIZE_X;
		maxCol = mAtlas->GetHeight() / TILE_SIZE_Y;
		
		mY = index / maxRow;
		mX = index % maxRow;
	}
	void Tile::Update()
	{
		GameObject::Update();
	}
	void Tile::Render()
	{
		BindConstantBuffer();

		GameObject::Render();
	}

	void Tile::BindConstantBuffer()
	{
		ya::renderer::uvCB uvCB = {};
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::UV];
		
		uvCB.LeftTop = Vector4(mX * 0.125f, mY * 0.1666f, 0.0f, 0.0f);

		cb->SetData(&uvCB);
		cb->Bind(eShaderStage::VS);
	}

	//void Tile::OnCollisionEnter(Collider* other)
	//{
	//	//GameObject* obj = other->GetOwner();

	//	//Rigidbody* rb = obj->GetComponent<Rigidbody>();

	//	//if (rb == nullptr)
	//	//{
	//	//	return;
	//	//}

	//	//rb->SetGround(true);


	//	//Collider* objCol = obj->GetComponent<Collider>();
	//	//Vector2 objPos = objCol->GetPos();

	//	//Collider* groundCol = this->GetComponent<Collider>();
	//	//Vector2 groundPos = groundCol->GetPos();

	//	//float fLen = fabs(objPos.y - groundPos.y);


	//	//float fSize = (objCol->GetSize().y / 2.0f) + (groundCol->GetSize().y / 2.0f);

	//	//if (fLen < fSize)
	//	//{
	//	//	Transform* objTr = obj->GetComponent<Transform>();
	//	//	Transform* grTr = this->GetComponent<Transform>();

	//	//	Vector2 objPos = objTr->GetPos();
	//	//	Vector2 grPos = grTr->GetPos();

	//	//	objPos.y -= (fSize - fLen) - 1.0f;
	//	//	objTr->SetPos(objPos);
	//	//}
	//}

	//void Tile::OnCollisionStay(Collider* other)
	//{
	//}

	//void Tile::OnCollisionExit(Collider* other)
	//{
	//	//GameObject* obj = other->GetOwner();

	//	//Rigidbody* rb = obj->GetComponent<Rigidbody>();
	//	//if (rb == nullptr)
	//	//	return;

	//	//rb->SetGround(false);
	//}
}