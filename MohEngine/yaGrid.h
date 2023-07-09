#pragma once
#include "yaGameObject.h"

namespace ya
{
	class GridScript;
	class Grid : public GameObject
	{
	public:
		Grid();
		~Grid();

		virtual void Intialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		GridScript* GetScript() { return mScript; }
	private:
		GridScript* mScript;
	};
}
