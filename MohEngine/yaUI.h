#pragma once
#include "yaGameObject.h"
#include "yaMesh.h"
#include "yaMaterial.h"

namespace ya
{
	class UI : public GameObject
	{
	public:

		UI(Vector3 pos, const std::wstring& materialname);
		UI(GameObject* obj,Vector3 pos, const std::wstring& materialname);
		~UI();

		virtual void Intialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		Vector3 GetScale() { return mScale; }

	private:
		std::shared_ptr<Mesh> mMesh;
		std::shared_ptr<Material> mMaterial;

		Vector3 mPositon;
		Vector3 mScale;
		
	};
}
