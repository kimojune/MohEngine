#pragma once
#include "yaComponent.h"
#include "yaTexture.h"
#include "yaAnimation.h"

namespace ya
{

	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};

		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

		Animator();
		~Animator();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
		
		void Create(std::wstring name
			, std::shared_ptr<graphics::Texture> atlas
			, Vector2 leftTop
			, Vector2 size
			, UINT coulumnLength
			, Vector2 offset = Vector2::Zero
			, float duration = 0.0f);

	private:
		std::map < std::wstring, Animation*> mAnimations;
		std::map < std::wstring, Events*> mEvents;
		Animation* mActiveAnimation;

		bool mbLoop;
	};

}