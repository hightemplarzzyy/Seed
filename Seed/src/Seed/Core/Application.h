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
		uint32_t WindowWidth, WindowHeight, APIType;
	};

	class Application
	{
	public:
		Application(const ApplicationProps& props = {"Seed Engine", 1280, 720, 1});
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

		static uint32_t& APIType()
		{
			static uint32_t s_APIType;
			return s_APIType;
		}

		float GetTime() const; // TODO: This should be in "Platform"
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		Scope<Window> m_Window;
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
