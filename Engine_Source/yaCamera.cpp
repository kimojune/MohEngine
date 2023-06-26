#include "yaCamera.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaApplication.h"

extern ya::Application application;

namespace ya
{
	Matrix Camera::mView = Matrix::Identity;
	Matrix Camera::mProjection = Matrix::Identity;

	Camera::Camera()
		:Component(eComponentType::Camera)
		,mType(eProjectionType::OrthoGraphic)
		,mAspectRatio(1.0f)
		,mNear(1.0f)
		,mFar(1000.0f)
		,mSize(10.0f)
	{
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
	}
	void Camera::Render()
	{
	}
	bool Camera::CreateViewMatrix()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		pos.z -= 10.0f;
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
			float OrthorGraphicRatio = mSize / 800.0f;
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
}
