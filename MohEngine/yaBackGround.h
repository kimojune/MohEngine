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
		BackGround(Vector3 pos, const std::wstring& materialname);
		~BackGround() override;

		virtual void Intialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetPosition(Vector3 pos) { mPositon = pos; }
		void SetScale(Vector3 scale) { mScale = scale; }

	private:
		std::shared_ptr<Mesh> mMesh;
		std::shared_ptr<Material> mMaterial;

		Vector3 mPositon;
		Vector3 mScale;
	};
}

