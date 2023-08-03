#include "yaAnimation.h"
#include "yaTime.h"
#include "yaRenderer.h"
#include "yaConstantBuffer.h"

namespace ya
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, mAtlas(nullptr)
		, mAnimator(nullptr)
		, mSprites{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
		, mFlip(ya::enums::eFlipType::None)
	{
	}
	Animation::~Animation()
	{
		mSprites.clear();
	}
	void Animation::Update()
	{
	}
	void Animation::LateUpdate()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mSprites[mIndex].duration <= mTime)
		{
			mIndex++;
			mTime = 0.0f;

			if (mSprites.size() <= mIndex)
			{
				mIndex = mSprites.size() - 1;
				mbComplete = true;
			}
		}
	}
	void Animation::Render()
	{
	}
	void Animation::Create(std::wstring name
		, std::shared_ptr<graphics::Texture> atlas
		, Vector2 leftTop
		, Vector2 size
		, UINT columnLength
		, Vector2 offset
		, float duration
	)
	{
		SetKey(name);
		mAtlas = atlas;

		Vector2 mAtlasSize = atlas->GetSize();
		float mRatio = 30.0f;

		for (size_t i = 0; i < columnLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (i * size.x) / mAtlasSize.x;
			sprite.leftTop.y = leftTop.y / mAtlasSize.y;
			sprite.size.x = size.x / mAtlasSize.x;
			sprite.size.y = size.y / mAtlasSize.y;
			sprite.offset = offset;
			sprite.outputSize = Vector2(size.x / mAtlasSize.x, size.y / mAtlasSize.y);
			sprite.duration = duration;

			mSprites.push_back(sprite);
		}

	}
	void Animation::Binds()
	{
		// texture bind
		mAtlas->BindShader(graphics::eShaderStage::PS, 12);

		//AnimationCB;
		renderer::AnimatorCB data = {};

		if (mFlip == eFlipType::X)
		{
			data.spriteLeftTop = Vector2(1.0f - (mSprites[mIndex].size.x) - mSprites[mIndex].leftTop.x
				, mSprites[mIndex].leftTop.y);
		}

		else
		{
			data.spriteLeftTop = mSprites[mIndex].leftTop;
		}
		data.spriteSize = mSprites[mIndex].size;
		data.spriteOffset = mSprites[mIndex].offset;
		data.outputSize = mSprites[mIndex].outputSize;
		data.animationType = (UINT)mFlip;

		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Animator];
		cb->SetData(&data);

		cb->Bind(eShaderStage::VS);
		cb->Bind(eShaderStage::PS);
	}
	void Animation::Reset()
	{
		mTime = 0.0f;
		mbComplete = false;
		mIndex = 0;
	}
}