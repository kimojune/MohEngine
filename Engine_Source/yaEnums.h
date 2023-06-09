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
		Script,
		Camera,
		End,
	};
	
	enum class eLayerType
	{
		Grid,
		Player,
		Tile,
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
		Image,
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

	enum class eCameraType
	{
		Main,
		UI,
		End,
	};
}