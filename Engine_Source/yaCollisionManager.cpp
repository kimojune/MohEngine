#include "yaCollisionManager.h"
#include "yaSceneManager.h"


namespace ya
{
	std::bitset<LAYER_MAX> CollisionManager::mMatrix[LAYER_MAX] = {};
	std::map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{
	}
	void CollisionManager::Update()
	{
		for (UINT column = 0; column < (UINT)eLayerType::End; column++)
		{
			for (UINT row = 0; row < (UINT)eLayerType::End; row++)
			{
				if (mMatrix[column][row] == true)
				{
					LayerCollision((eLayerType)column, (eLayerType)row);
				}
			}
		}
	}

	void CollisionManager::LayerCollision(eLayerType left, eLayerType right)
	{
		Scene* activeScene = SceneManager::GetActiveScene();

		const std::vector<GameObject*>& lefts
			= activeScene->GetLayer(left).GetGameObjects();
		const std::vector<GameObject*>& rights
			= activeScene->GetLayer(right).GetGameObjects();

		for (GameObject* leftObj : lefts)
		{
			Collider2D* leftCol = leftObj->GetComponent<Collider2D>();
			if (leftCol == nullptr)
				continue;
			if (leftObj->GetState() !=
				GameObject::eState::Active)
				continue;

			for (GameObject* rightObj : rights)
			{
				Collider2D* rightCol = rightObj->GetComponent<Collider2D>();
				if (rightCol == nullptr)
					continue;
				if (rightObj->GetState() !=
					GameObject::eState::Active)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}

	}

	void CollisionManager::ColliderCollision(Collider2D* left, Collider2D* right)
	{
		//�� �浹ü�� ID bool ���� Ȯ��
		ColliderID id = {};
		id.left = left->GetColliderID();
		id.Right = right->GetColliderID();

		//�浹 ������ �����´�
		std::map<UINT64, bool>::iterator iter
			= mCollisionMap.find(id.id);

		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		if (Intersect(left, right))
		{
			if (iter->second == false)
			{
				//���� �浹
				left->OnCollisionEnder(right);
				right->OnCollisionEnder(left);
			}

			else
			{
				//�浹 ��
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			// �浹 X
			if (iter->second == true)
			{
				// �浹�ϰ� �ִٰ� ������
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
			}
		}
	}
	bool CollisionManager::Intersect(Collider2D* left, Collider2D* right)
	{

		//�� �浹
		if (left->GetColliderType() == eColliderType::Circle 
			&& right->GetColliderType() == eColliderType::Circle)
		{	
		Vector3 leftPos = left->GetPosition();
		Vector3 rightPos = right->GetPosition();

		float leftRadius = left->GetRadius();
		float rightRadius = right->GetRadius();
		
		float sumRadius = leftRadius + rightRadius;

		float distance = 
		sqrt((rightPos.x - leftPos.x) * (rightPos.x - leftPos.x) + (rightPos.y - leftPos.y) * (rightPos.y - leftPos.y));
		
		if (distance <= sumRadius)
			return true;
		}

		return false;
	}
	void CollisionManager::SetLayer(eLayerType left, eLayerType right, bool enable)
	{
		UINT row = -1;
		UINT col = -1;

		UINT iLeft = (UINT)left;
		UINT iRight = (UINT)right;

		if (iLeft <= iRight)
		{
			row = iLeft;
			col = iRight;
		}
		else
		{
			row = iRight;
			col = iLeft;
		}

		mMatrix[col][row] = enable;
	}
	void CollisionManager::Clear()
	{
		mMatrix->reset();
		mCollisionMap.clear();
	}
}