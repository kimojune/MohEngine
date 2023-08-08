#pragma once
#include "yaGameObject.h"

namespace ya
{
	class ProjectileScript;
	class Projectile : public GameObject
	{
	public:
		Projectile();
		virtual ~Projectile();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		
		void SetDirection(Vector2 vector);
		void SetPos(Vector3 pos);

	private:
		GameObject* mOwner;
		ProjectileScript* mScript;
		
		Vector3 mPos;
		Vector2 directionVector;
		
		std::shared_ptr<class Texture> mTexture;
	};
}
