#pragma once
#include "yaComponent.h"
#include "yaGraphics.h"

namespace ya
{
	using namespace ya::graphics;
	class Light : public Component
	{
	public:
		Light();
		~Light();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		LightAttribute GetAttibute() { return mAttribute; }
		void SetType(eLightType type) { mAttribute.type = type; }
		void SetRadius(float radius) { mAttribute.radius = radius; }
		void SetAngle(float angle) { mAttribute.angle = angle; }
		void SetColor(Vector4 color) { mAttribute.color = color; }
		Vector4 GetColor() { return mAttribute.color; }
		eLightType GetType() { return mAttribute.type; }
		float GetRadius() { return mAttribute.radius; }
		float GetAngle() { return mAttribute.angle; }

	private:
		LightAttribute mAttribute;
	};
}

