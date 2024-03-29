#pragma once
#include "yaComponent.h"
#include "yaMesh.h"
#include "yaMaterial.h"

namespace ya
{

class MeshRenderer : public Component
{
public:
	MeshRenderer();
	~MeshRenderer();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	void SetMesh(std::shared_ptr<Mesh> mesh) { mMesh = mesh; }
	void SetMaterial(std::shared_ptr<Material> material) { mMaterial = material; }
	std::shared_ptr<Material> GetMaterial() { return mMaterial; }
	std::shared_ptr<Mesh> GetMesh() { return mMesh; }

	size_t GetWidth() {return mMaterial->GetWidth();}
	size_t GetHeight() {return mMaterial->GetHeight();}

private:
	std::shared_ptr<Mesh> mMesh;
	std::shared_ptr<Material> mMaterial;
};

}
