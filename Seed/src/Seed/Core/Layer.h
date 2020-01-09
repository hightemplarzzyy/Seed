#pragma once

#include "Core.h"
#include "TimeStep.h"
#include "Seed/Events/Event.h"

namespace Seed {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnUpdate(TimeStep ts) {};
		virtual void OnEvent(Event& event) {};
		virtual void OnImGuiRender() {};

		inline const std::string& GetName() const { return m_DebugName; };
	protected:
		std::string m_DebugName;
	};

}