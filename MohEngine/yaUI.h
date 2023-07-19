#pragma once
#include "yaGameObject.h"
#include "yaMesh.h"
#include "yaMaterial.h"

namespace ya
{
	class UI : public GameObject
	{
	public:

		UI(const std::wstring& materialname);
		UI(Vector3 pos, const std::wstring& materialname);
		UI(GameObject* obj,Vector3 pos, const std::wstring& materialname);
		~UI();

		virtual void Intialize() override;
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
