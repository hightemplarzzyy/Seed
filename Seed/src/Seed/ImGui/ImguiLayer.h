#pragma once

#include "../vendor/imgui/imgui.h"

#include "Seed/Core/Layer.h"
#include "Seed/Events/KeyboardEvent.h"
#include "Seed/Events/MouseEvent.h"
#include "Seed/Events/ApplicationEvents.h"

namespace Seed {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		ImGuiLayer(const std::string& name);
		virtual ~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};

}