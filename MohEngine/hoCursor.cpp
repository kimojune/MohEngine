#include "hoCursor.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaSceneManager.h"
#include "yaUICamera.h"
#include "yaCamera.h"
#include "yaApplication.h"

extern ya::Application application;

namespace ho
{
	using namespace ya;

	Cursor::Cursor(GameObject* camera)
		:mPos(Vector3(0.0f, 0.0f, -10.0f))
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector3(13.0f, 13.0f, 1.0f));
		tr->SetPosition(Vector3::One);
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"reticle_crosshair_002_material"));

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, this);
		mCamera = camera;
		SetName(L"Cursor");
	}
	Cursor::~Cursor()
	{
	}
	void Cursor::Intialize()
	{

	}
	void Cursor::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 Pos = ya::Input::GetMousePos() ;
		mPos = Vector3(Pos.x, Pos.y, -10.0f);
		Camera* camera = mCamera->GetComponent<Camera>();
		tr->SetPosition(camera->GetWorldTransform(mPos));
		
		GameObject::Update();
	}
	void Cursor::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Cursor::Render()
	{
		GameObject::Render();
	}
	//Vector3 Cursor::TranslateWorldPos(Vector3 pos)
	//{		
	//	Camera* camera = mCamera->GetComponent<Camera>();
	//	
	//	Vector3 mpos = Vector3(pos.x, pos.y, pos.z);
	//	Matrix projection = camera->GetmProjection();
	//	Matrix view = camera->GetmView();
	//	Matrix world = Matrix::Identity;

	//	RECT rt = {};
	//	GetClientRect(application.GetHwnd(), &rt);

	//	Viewport viewport(rt);
	//	Vector3 translatePos = viewport.Unproject(mpos, projection, view, world);
	//	//Vector3 Project(const Vector3 & p, const Matrix & proj, const Matrix & view, const Matrix & world) const noexcept;
	//	
	//	return Vector3(translatePos.x, translatePos.y, translatePos.z);
	//}
}