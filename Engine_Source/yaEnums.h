#pragma once

namespace ya::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Collider2D,
		Particle,
		MeshRender,
		Animator,
		Script,
		Light,
		Camera,
		End,
	};
	
	enum class eLayerType
	{
		Grid,
		Player,
		Tile,
		Light,
		Companions,
		Monster,
		UI,
		BG,
		End = 16,
	};

	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		Animation,
		Image,
		End,
	};

	enum class eCameraType
	{
		Main,
		UI,
		End,
	};

	enum class eColliderType
	{
		Rect,
		Circle,
		Sphere,
		Cube,
		End,
	};

	enum class eDirection
	{
		Left,
		Right,
		Up,
		Down,
		LeftUp,
		LeftDown,
		RightUp,
		RightDown,
		End,
	};

	enum class eLightType
	{
		Directional,
		Point,
		Spot,
		End,
	};
}