#include "hoCursor.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaSceneManager.h"
#include "yaUICamera.h"
#include "yaCamera.h"


namespace ho
{
	using namespace ya;

	Cursor::Cursor(GameObject* camera)
		:mPos(Vector3(0.0f, 0.0f, -10.0f))
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector3(13.0f, 13.0f, 1.0f));
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
		tr->SetPosition(TranslateWorldPos(mPos));
		
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
	Vector3 Cursor::TranslateWorldPos(Vector3 pos)
	{
		Vector4 mpos = Vector4(pos.x, pos.y, pos.z, 1.0f);
		Camera* camera = mCamera->GetComponent<Camera>();
		Matrix viewInverse = camera->GetViewInverseMatrix();
		Matrix projectionInverse = camera->GetProjectionInverseMatrix();
		
		Vector4 translateProjectionPos = XMVector4Transform(mpos, projectionInverse);
		Vector4 translatePos = XMVector4Transform(translateProjectionPos, viewInverse);
		
		
		return Vector3(translatePos.x, translatePos.y, translatePos.z);
	}
}