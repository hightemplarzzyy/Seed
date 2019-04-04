#pragma once

#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Seed/Events/Event.h"
#include "Seed/Events/ApplicationEvents.h"

#include "Seed/ImGui/imguilayer.h"

namespace Seed {

	class SEED_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	//To be defined in the client
	Application* CreateApplication();
}
