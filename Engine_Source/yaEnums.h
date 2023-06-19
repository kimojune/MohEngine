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
		End,
	};
	
	enum class eLayerType
	{
		Player,
		Monster,
		UI,
		End,
	};
}