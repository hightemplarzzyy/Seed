#pragma once

#include "Core.h"
#include "TimeStep.h"
#include "Window.h"
#include "LayerStack.h"
#include "Seed/Events/Event.h"
#include "Seed/Events/ApplicationEvents.h"

#include "Seed/ImGui/ImguiLayer.h"

namespace Seed {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		virtual void OnInit() {}
		virtual void OnShutdown() {}
		virtual void OnUpdate() {}
		virtual void OnUpdate(TimeStep ts) {}
		virtual void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void RenderImGui();

		std::string OpenFile(const std::string& filter) const;

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

		float GetTime() const; // TODO: This should be in "Platform"
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;
		TimeStep m_TimeStep;

		float m_LastFrameTime = 0.0f;

		static Application* s_Instance;
	};

	//Implement by client
	Application* CreateApplication();
}
