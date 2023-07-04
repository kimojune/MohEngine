#include "yaTransform.h"
#include "yaRenderer.h"
#include "yaCamera.h"

namespace ya
{
	using namespace ya::graphics;
	Transform::Transform()
		: Component(eComponentType::Transform)
		,mPosition(Vector3::Zero)
		,mRotation(Vector3::Zero)
		,mScale(Vector3::One)

	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
		// 이동 회전 크기 변경
	}
	void Transform::LateUpdate()
	{
		mWorld = Matrix::Identity;

		Matrix scale = Matrix::CreateScale(mScale);

		Matrix rotation;
		rotation = Matrix::CreateRotationX(mRotation.x);
		rotation *= Matrix::CreateRotationY(mRotation.y);
		rotation *= Matrix::CreateRotationZ(mRotation.z);

		Matrix position;
		position.Translation(mPosition);
		
		mWorld = scale * rotation * position;


		mUp = Vector3::TransformNormal(Vector3::Up, rotation);

		mForward = Vector3::TransformNormal(Vector3::Forward, rotation);

		mRight = Vector3::TransformNormal(Vector3::Right, rotation);


		if (mParent)
		{
			Vector3 parentScale = mParent->mScale;
			Vector3 inversescale = Vector3(1.0f / parentScale.x, 1.0f / parentScale.y, 1.0f / parentScale.z);
			Matrix parentScaleInverse = Matrix::CreateScale(inversescale);
			mWorld *= parentScaleInverse * mParent->mWorld ;
		}
		//CreateRotationX Matrix
		//XMMATRIX M;
		//M.m[0][0] = 1.0f;	 M.m[1][0] = 0.0f;		 M.m[2][0] = 0.0f;			M.m[3][0] = 0.0f;
		//M.m[0][1] = 0.0f;	 M.m[1][1] = fCosAngle;	 M.m[2][1] = -fSinAngle;	M.m[3][1] = 0.0f;
		//M.m[0][2] = 0.0f;	 M.m[1][2] = fSinAngle;	 M.m[2][2] = fCosAngle;		M.m[3][2] = 0.0f;
		//M.m[0][3] = 0.0f;	 M.m[1][3] = 0.0f;		 M.m[2][3] = 0.0f;			M.m[3][3] = 1.0f;

		//CreateRotationY Matrix
		//XMMATRIX M;
		//M.m[0][0] = fCosAngle; M.m[1][0] = 0.0f;  M.m[2][0] = fSinAngle;   M.m[3][0] = 0.0f;
		//M.m[0][1] = 0.0f;	     M.m[1][1] = 1.0f;  M.m[2][1] = 0.0f;		 M.m[3][1] = 0.0f;
		//M.m[0][2] = -fSinAngle M.m[1][2] = 0.0f;; M.m[2][2] = fCosAngle;   M.m[3][2] = 0.0f;
		//M.m[0][3] = 0.0f;	     M.m[1][3] = 0.0f;  M.m[2][3] = 0.0f;		 M.m[3][3] = 1.0f;


		//CreateRotation Z Matrix
		//XMMATRIX M;
		//M.m[0][0] = fCosAngle; M.m[1][0] = -fSinAngle; M.m[2][0] = 0.0f;  M.m[3][0] = 0.0f;
		//M.m[0][1] = fSinAngle; M.m[1][1] = fCosAngle;  M.m[2][1] = 0.0f;  M.m[3][1] = 0.0f;
		//M.m[0][2] = 0.0f;	   M.m[1][2] = 0.0f;	   M.m[2][2] = 1.0f;  M.m[3][2] = 0.0f;
		//M.m[0][3] = 0.0f;	   M.m[1][3] = 0.0f;	   M.m[2][3] = 0.0f;  M.m[3][3] = 1.0f;

	}
	void Transform::Render()
	{
	}
	void Transform::BindConstantBuffer()
	{
		renderer::TransformCB trCB = {};

		trCB.mWorld = mWorld;
		trCB.mView = Camera::GetViewMatrix();
		trCB.mProjection = Camera::GetProjectionMatrix();

		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Transform];

		cb->SetData(&trCB);
		cb->Bind(eShaderStage::VS);

	}
	Vector3 Transform::TranslateWorldMatrix(Vector3 vector)
	{
		Matrix mView = Camera::GetViewMatrix();
		Matrix mProjection = Camera::GetProjectionMatrix();

		Matrix mViewReverce = mView.Invert();
		Matrix mProjectionReverce = mProjection.Invert();

		Vector4 cameraPos = Vector4::Transform(Vector4(vector.x, vector.y, vector.z, 1.0f), mProjectionReverce);
		Vector4 worldpos = Vector4::Transform(Vector4(vector.x, vector.y, vector.z, 1.0f), mViewReverce);
		
		mPosition = vector;

		return Vector3(worldpos.x, worldpos.y, worldpos.z)/ worldpos.w;
	}
}