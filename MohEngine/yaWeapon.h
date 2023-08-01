#pragma once
#include "yaGameObject.h"
#include "yaMesh.h"
#include "yaMaterial.h"


namespace ya
{
	class Animator;
	class Weapon : public GameObject
	{
	public:

		enum class eWeaponType
		{
			Automatic,
			Semiautomatic,
			Charged,
			Beam,
			Burst,
			End,
		};

		enum class eQuality
		{
			None,
			D,
			C,
			B,
			A,
			S,
			End,
		};

		struct WeaponInfo
		{
			eWeaponType type;
			eQuality quality;

			int magazineSize;
			int maxAmmo;
			float reloadTime;
			UINT damage;
			float fireRate_Manual;
			float fireRate_Automatic;

			float shootSpeed;
			float range;

			float force;
			float spreadDegree;

			UINT price;
		};
		
		
		Weapon();
		virtual ~Weapon() override;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetMesh(std::shared_ptr<Mesh> mesh) { mMesh = mesh; }
		void SetMaterial(std::shared_ptr<Material> material) { mMaterial = material; }

		void SetInfo(WeaponInfo info) { mInfo = info; }

	private:
		std::shared_ptr<Mesh> mMesh;
		std::shared_ptr<Material> mMaterial;

		WeaponInfo mInfo;
		Animator* ActiveAnimator;

	};
}