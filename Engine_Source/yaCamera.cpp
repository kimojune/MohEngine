#include "yaCamera.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaApplication.h"
#include "yaRenderer.h"
#include "yaScene.h"
#include "yaSceneManager.h"
#include "yaMeshRenderer.h"

extern ya::Application application;

namespace ya
{
	Matrix Camera::View = Matrix::Identity;
	Matrix Camera::Projection = Matrix::Identity;

	Camera::Camera()
		:Component(eComponentType::Camera)
		,mType(eProjectionType::OrthoGraphic)
		,mAspectRatio(1.0f)
		,mNear(1.0f)
		,mFar(1000.0f)
		,mSize(6.0f)
		, mLayerMask{}
		, mOpaqueGameObjects{}
		, mCutOutGameObjects{}
		, mTransparentGameObjects{}
		, mView(Matrix::Identity)
		, mProjection(Matrix::Identity)
	{
		EnableLayerMasks();
	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
	}
	void Camera::Update()
	{
	}
	void Camera::LateUpdate()
	{
		CreateViewMatrix();
		CreateProjectionMatrix(mType);
		RegisterCameraInRenderer();
	}
	void Camera::Render()
	{
		View = mView;
		Projection = mProjection;

		SortGameObjects();

		RenderOpaque();
		RenderCutOut();
		RenderTransparent();
	}
	bool Camera::CreateViewMatrix()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		//View Translate Matrix
		mView = Matrix::Identity;
		mView *= Matrix::CreateTranslation(-pos);


		//View Rotate Matrix
		Vector3 up = tr->Up();
		Vector3 right = tr->Right();
		Vector3 forward = tr->Forward();

		Matrix viewRotate;
		viewRotate._11 = right.x;	viewRotate._12 = up.x;	viewRotate._13 = forward.x;
		viewRotate._21 = right.y;	viewRotate._22 = up.y;	viewRotate._23 = forward.y;
		viewRotate._31 = right.z;	viewRotate._32 = up.z;	viewRotate._33 = forward.z;
		mView *= viewRotate;
		
		return true;
	}

	bool Camera::CreateProjectionMatrix(eProjectionType)
	{
		RECT rect = {};
		GetClientRect(application.GetHwnd(), &rect);
		float width = rect.right - rect.left;
		float height = rect.bottom - rect.top;
		mAspectRatio = width / height;


		if (mType == eProjectionType::OrthoGraphic)
		{
			float OrthorGraphicRatio = mSize /10;
			width *= OrthorGraphicRatio;
			height *= OrthorGraphicRatio;

			mProjection = Matrix::CreateOrthographicLH(width, height, mNear, mFar);
		}

		else
		{
			mProjection = Matrix::CreatePerspectiveFieldOfViewLH(XM_2PI / 6.0f, mAspectRatio, mNear, mFar);
		}

		return true;
	}
	void Camera::RegisterCameraInRenderer()
	{
		renderer::cameras.push_back(this);
	}

	void Camera::TurnLayerMask(eLayerType type, bool enable)
	{
		mLayerMask.set((UINT)type, enable);
	}
	void Camera::SortGameObjects()
	{
		mOpaqueGameObjects.clear();
		mCutOutGameObjects.clear();
		mTransparentGameObjects.clear();

		Scene* scene = SceneManager::GetActiveScene();

		for (size_t i = 0; i < (UINT)eLayerType::End ; i++)
		{
			if (mLayerMask[i] == true)
			{
				Layer& layer = scene->GetLayer((eLayerType)i);
				const std::vector<GameObject*> gameObjs = layer.GetGameObjects();

				for (GameObject* obj : gameObjs)
				{
					MeshRenderer* mr = obj->GetComponent<MeshRenderer>();
					if (mr == nullptr)
						continue;

					std::shared_ptr<Material> mt = mr->GetMaterial();
					eRenderingMode mode = mt->GetRenderingMode();
					switch (mode)
					{
					case eRenderingMode::Opaque:
						mOpaqueGameObjects.push_back(obj);
						break;
					case eRenderingMode::CutOut:
						mCutOutGameObjects.push_back(obj);
						break;
					case eRenderingMode::Transparent:
						mTransparentGameObjects.push_back(obj);
						break;
					default:
						break;
					}

				}

			}
		}
	}
	
	void Camera::RenderOpaque()
	{
		for (GameObject* gameObj : mOpaqueGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render();
		}
	}
	void Camera::RenderCutOut()
	{
		for (GameObject* gameObj : mCutOutGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render();
		}
	}
	void Camera::RenderTransparent()
	{
		for (GameObject* gameObj : mTransparentGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render();
		}
	}
}
