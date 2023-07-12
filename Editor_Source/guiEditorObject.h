#pragma once
#include "yaGameObject.h"

namespace gui
{
	class EditorObject : public ya::GameObject
	{
	public:
		EditorObject();
		virtual ~EditorObject();

		virtual void Intialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	};
}
