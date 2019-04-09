#pragma once

#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Seed/Events/Event.h"
#include "Seed/Events/ApplicationEvents.h"

#include "Seed/ImGui/ImguiLayer.h"

namespace Seed {

	class SEED_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		virtual void OnInit() {};
		virtual void OnShutdown() {};
		virtual void OnUpdate() {};

		virtual void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void RenderImGui();

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		static Application* s_Instance;
	};

	//Implement by client
	Application* CreateApplication();
}
