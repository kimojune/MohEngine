#include "guiEditor.h"
#include "yaMesh.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaMaterial.h"
#include "yaGridScript.h"
#include "yaRenderer.h"

namespace gui
{
	using namespace ya::enums;
	std::vector<Widget*> Editor::mWidgets = {};
	std::vector<EditorObject*> Editor::mEditorObjects = {};
	std::vector<DebugObject*> Editor::mDebugObjects = {};

	void Editor::Initialize()
	{
		mDebugObjects.resize((UINT)eColliderType::End);

		std::shared_ptr<ya::Mesh>mesh 
			= ya::Resources::Find<ya::Mesh>(L"DebugRect");
		std::shared_ptr<ya::Material> material
			= ya::Resources::Find<ya::Material>(L"DebugMaterial");

		mDebugObjects[(UINT)eColliderType::Rect] = new DebugObject();
		mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<ya::Transform>();
		ya::MeshRenderer* mr
			= mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<ya::MeshRenderer>();
		mr->SetMaterial(material);
		mr->SetMesh(mesh);

		EditorObject* grid = new EditorObject();
		grid->SetName(L"Grid");

		mr = grid->AddComponent<ya::MeshRenderer>();
		mr->SetMesh(ya::Resources::Find<ya::Mesh>(L"RectMesh"));
		mr->SetMaterial(ya::Resources::Find<ya::Material>(L"GridMaterial"));
		ya::GridScript* gridSc = grid->AddComponent<ya::GridScript>();
		gridSc->SetCamera(ya::renderer::cameras[0]);

		mEditorObjects.push_back(grid);
	}
	void Editor::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Editor::Update()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->Update();
		}
	}
	void Editor::LateUpdate()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->LateUpdate();
		}
	}
	void Editor::Render()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->Render();
		}

		for (const ya::graphics::DebugMesh& mesh
			: ya::renderer::debugMeshes)
		{
			DebugRender(mesh);
		}
	}
	void Editor::Release()
	{

	}
	void Editor::DebugRender(const ya::graphics::DebugMesh& mesh)
	{
		DebugObject* debugObj = mDebugObjects[(UINT)mesh.type];

		// 위치 크기 회전 정보를 받아와서
		// 해당 게임오브젝트위에 그려주면된다.

		debugObj->Render();
	}
}