#pragma once
#include "yaComponent.h"
#include "yaMesh.h"
#include "yaShader.h"

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

private:
	Mesh* mMesh;
	Shader* mShader;
};

}
