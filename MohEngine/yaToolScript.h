#pragma once
#include "yaScript.h"
namespace ya
{
	class ToolScript: public Script
	{
	public:
		ToolScript();
		~ToolScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetIndex(int index) { mIndex = index; }

	private:
		int mIndex;
	};
}
