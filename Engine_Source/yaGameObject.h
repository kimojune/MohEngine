#pragma once
#include "yaEntity.h"
#include "yaComponent.h"

namespace ya
{
	class GameObject : public Entity
	{
	public:
		enum eState
		{
			Active,
			Paused,
			Dead,
		};

		GameObject();
		virtual ~GameObject();

		virtual void Intialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		template <typename T>
		T* GetComponent()
		{
			T* comp;
			for (T* component : mComponents)
			{
				Component* buff = dynamic_cast<T*>(comp);

				if (buff != nullptr)
					return component;
			}

			return nullptr;
		}

		template <typename T>
		T* AddComponet()
		{
			T* comp = new T();

			Component* buff = dynamic_cast<T*>(comp);

			if (buff == nullptr)
				return nullptr;

			mComponents.push_back(buff);

			return comp;
		}

	private:
		eState mState;
		std::vector<Component*> mComponents;
	};
}