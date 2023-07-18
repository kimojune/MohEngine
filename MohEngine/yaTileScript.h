#pragma once
#include "yaScript.h"
namespace ya
{
	class TileScript: public Script
	{
	public:
		TileScript();
		~TileScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetIndex(int index) { mIndex = index; }

	private:
		int mIndex;
	};
}
