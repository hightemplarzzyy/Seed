#pragma once

#include "Seed/Core/Window.h"
#include "Seed/Core/Log.h"
#include "Seed/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Seed {

	class WindowsGLFWWindow : public Window
	{
	public:
		WindowsGLFWWindow(const WindowProperties& props);
		virtual ~WindowsGLFWWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
		virtual std::pair<float, float> GetWindowPos() const override;

		//Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
		float m_LastFrameTime = 0.0f;
	};

}