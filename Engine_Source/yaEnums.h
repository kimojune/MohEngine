#pragma once

namespace ya::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Particle,
		MeshRender,
		Script,
		Camera,
		End,
	};
	
	enum class eLayerType
	{
		Player,
		Companions,
		Monster,
		UI,
		End,
	};

	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		End,
	};
}