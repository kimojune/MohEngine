#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Mesh;
	class graphics::Material;
	class BackGround : public GameObject
	{
	public:
		BackGround();
		BackGround(Vector3 pos, Vector3 scale);
		~BackGround() override;

		virtual void Intialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetMaterial(const std::wstring& materialname)
		{
			mMaterial = Resources::Find<Material>(materialname);
		}

		void SetPosition(Vector3 pos) { mPositon = pos; }
		void SetScale(Vector3 scale) { mScale = scale; }

	private:
		std::shared_ptr<Mesh> mMesh;
		std::shared_ptr<Material> mMaterial;

		Vector3 mPositon;
		Vector3 mScale;
	};
}

