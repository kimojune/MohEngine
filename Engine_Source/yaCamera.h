#pragma once
#include "yaComponent.h"
//#include "yaGraphics.h"

namespace ya
{
	class Camera : public Component
	{
	public:
		enum class eProjectionType
		{
			Perpective,
			OrthoGraphic,
			None
		};

		static Matrix& GetGpuViewMatrix() { return View; }
		static void SetGpuViewMatrix(Matrix view) { View = view; }
		static Matrix& GetGpuProjectionMatrix() { return Projection; }
		static void SetGpuProjectionMatrix(Matrix projection) { Projection = projection; }

		Camera();
		~Camera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		bool CreateViewMatrix();
		bool CreateProjectionMatrix(eProjectionType);
		void RegisterCameraInRenderer();

		void TurnLayerMask(eLayerType type, bool enable = true);
		void EnableLayerMasks() { mLayerMask.set(); }
		void DisableLayerMasks() { mLayerMask.reset(); }

		void AlphaSortGameObjects();
		void ZSortTransparencyGameObjects();
		void DivideAlphaBlendGameObjects(const std::vector<GameObject*> gameObjs);
		
		void RenderOpaque();
		void RenderCutOut();
		void RenderTransparent();

		void EnableDepthStencilState();
		void DisableDepthStencilState();
		
		void SetSize(float size) { mSize = size; }
		void SetType(eProjectionType type) { mType = type; }

		float GetSize() { return mSize; }

		Vector3 GetWorldTransform(Vector3 pos);

		Matrix& GetViewMatrix() { return mView; }
		Matrix& GetProjectionMatrix() { return mProjection; }
	
	private:
		static Matrix View;
		static Matrix Projection;

		Matrix mView;
		Matrix mProjection;

		eProjectionType mType;
		float mAspectRatio;
		float mNear;
		float mFar;
		float mSize;

		std::bitset<(UINT)eLayerType::End>  mLayerMask;
		std::vector<GameObject*> mOpaqueGameObjects;
		std::vector<GameObject*> mCutOutGameObjects;
		std::vector<GameObject*> mTransparentGameObjects;

	};
}

