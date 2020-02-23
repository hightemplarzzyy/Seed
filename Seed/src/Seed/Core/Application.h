#pragma once

#include "Core.h"
#include "TimeStep.h"
#include "Window.h"
#include "LayerStack.h"
#include "Seed/Events/Event.h"
#include "Seed/Events/ApplicationEvents.h"

#include "Seed/ImGui/ImguiLayer.h"

namespace Seed {

	struct ApplicationProps
	{
		std::string name;
		uint32_t WindowWidth, WindowHeight;
		std::string RenderAPI, Platform;
	};

	class Application
	{
	public:
		Application(const ApplicationProps& props = {"Seed Engine", 1280, 720, "OpenGL", "Windows"});
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

		std::string& RenderAPIType()
		{
			return m_Props.RenderAPI;
		}

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		Scope<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;
		TimeStep m_TimeStep;
		ApplicationProps m_Props;

		float m_LastFrameTime = 0.0f;

		static Application* s_Instance;
	};

	//Implement by client
	Application* CreateApplication();
}
