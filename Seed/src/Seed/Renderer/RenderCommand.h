#pragma once

#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Seed {

	class RenderCommand
	{
	public:
		inline static void Init()
		{
			GetAPI().Init();
		}

		inline static void SetViewport(uint32_t width, uint32_t height)
		{
			GetAPI().SetViewPort(0, 0, width, height);
		}

		inline static void SetClearColor(float r, float g, float b, float a)
		{

		}

		inline static void Clear()
		{
			GetAPI().Clear(0.0f, 0.0f, 0.0f, 0.0f);
		}
		inline static void Clear(float r, float g, float b, float a = 1.0f)
		{
			GetAPI().Clear(r, g, b, a);
		}

		inline static void DrawIndexed(uint32_t count, bool depthTest = true)
		{
			GetAPI().DrawIndexed(count, depthTest);
		}

		static RendererAPI& GetAPI()
		{
			static RendererAPI* s_RendererAPI = RendererAPI::Create();
			return *s_RendererAPI;
		}

	};

}