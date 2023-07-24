#pragma once
#include "yaGameObject.h"
#include "yaMesh.h"
#include "yaMaterial.h"

namespace ya
{
	class BackGround : public GameObject
	{
	public:
		BackGround();
		BackGround(const std::wstring& materialname);
		BackGround(GameObject* obj, const std::wstring& materialname);
		~BackGround() override;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetPosition(Vector3 pos);
		void SetScale(Vector3 scale);
		
		float GetWidth() { return mScale.x; }
		float GetHeight() { return mScale.y; }

	private:
		std::shared_ptr<Mesh> mMesh;
		std::shared_ptr<Material> mMaterial;
		
		Vector3 mPosition;
		Vector3 mScale;
	};
}

