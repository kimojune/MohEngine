#pragma once
#include "yaEntity.h"
#include "yaLayer.h"

namespace ya
{

class Scene : public Entity
{
public:
	Scene();
	virtual ~Scene();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
	virtual void Destroy();

	virtual void OnEnter();
	virtual void OnExit();

	virtual float GetCameraSize();

	Vector2 GetCursorDirectionVector(eCameraType type, GameObject* obj);

	void AddGameObject(eLayerType type, GameObject* gameObj);

	template <typename T>
	std::vector<GameObject*> FindObjectsofType()
	{
		std::vector<T*> findObjs = {};
		for (Layer* layer : mLayers)
		{
			auto gameObjs = layer->GetGameObjects();
			for (GameObject* obj : gameObjs)
			{
				T* buff = dynamic_cast<T*>(obj);
				if (buff != nullptr)
					findObjs.push_back(buff);
			}
		}

		return findObjs;
	}

	Layer& GetLayer(eLayerType type) { return mLayers[(UINT)type]; }

private:
	std::vector<Layer> mLayers;
};

}
