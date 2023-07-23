#include "yaAnimator.h"
#include "yaResources.h"

namespace ya
{
	Animator::Animator()
		:Component(enums::eComponentType::Animator)
	{
	}
	Animator::~Animator()
	{
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render()
	{
	}
	void Animator::Create(std::wstring name
		, std::shared_ptr<graphics::Texture> atlas
		, Vector2 leftTop
		, Vector2 size
		, UINT columnLength
		, Vector2 offset
		, float duration)
	{
		Animation* animation = FindAnimation(name);
		if (nullptr != animation)
			return;

		animation = new Animation();
		animation->SetKey(name);

		animation->Create(name
			, atlas
			, leftTop
			, size
			, columnLength
			, offset
			, duration);

		mAnimations.insert(std::make_pair(name, animation));

		Events* events = FindEvents(name);
		if (events != nullptr)
			return;

		events = new Events();
		mEvents.insert(std::make_pair(name, events));

	}
	Animation* Animator::CreateAnimations(const std::wstring& path, float duration)
	{
		size_t maxwidth = 0;
		size_t maxheight = 0;
		UINT fileCount = 0;

		std::filesystem::path fs(path);
		std::vector<std::shared_ptr<Texture>> textures = {};
		for (const auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = p.path().wstring(); // Use the full path from the iterator

			const std::wstring ext = p.path().extension();

			std::shared_ptr<Texture> tex = Resources::Load<Texture>(fileName, fullName);

			if (maxwidth < tex->GetWidth())
			{
				maxwidth = tex->GetWidth();
			}
			if (maxheight < tex->GetHeight())
			{
				maxheight = tex->GetHeight();
			}

			textures.push_back(tex);

			fileCount++;
		}

		std::wstring key = fs.parent_path().filename();
		key += fs.filename();

		mImageAtlas = std::make_shared<graphics::Texture>();
		mImageAtlas->CreateTex(path, fileCount, maxwidth, maxheight);
		Create(key, mImageAtlas, Vector2(0.0), Vector2(maxwidth, maxheight), fileCount, Vector2::Zero, duration);


		return nullptr;
	}
	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		std::map<std::wstring, Events*>::iterator iter
			= mEvents.find(name);

		if (iter == mEvents.end())
			return nullptr;

		return iter->second;
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator iter
			= mAnimations.find(name);

		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}
	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* prevAnimation = mActiveAnimation;

		Events* events;
		if (prevAnimation != nullptr)
		{

			events = FindEvents(prevAnimation->GetKey());
			if (events)
				events->endEvent();
		}

		Animation* animation = FindAnimation(name);
		if (animation)
		{
			mActiveAnimation = animation;
		}

		events = FindEvents(mActiveAnimation->GetKey());
		if (events)
			events->startEvent();

		mbLoop = loop;
		mActiveAnimation->Reset();
	}
	void Animator::Binds()
	{
		if (mActiveAnimation == nullptr)
			return;

		mActiveAnimation->Binds();
	}
	std::function<void()>& Animator::StartEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->startEvent.mEvent;
	}

	std::function<void()>& Animator::CompleteEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->completeEvent.mEvent;
	}

	std::function<void()>& Animator::EndEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->endEvent.mEvent;
	}
}