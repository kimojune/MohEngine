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
		Grid,
		Player,
		Companions,
		Monster,
		UI,
		BG,
		End,
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
}