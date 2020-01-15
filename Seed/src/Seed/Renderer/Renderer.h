#pragma once

#include "RenderCommand.h"
#include "Shader.h"

namespace Seed {

	class ShaderLibrary;

	class Renderer
	{
	public:
		static void Clear();
		static void Clear(float r, float g, float b, float a = 1.0f);
		static void SetClearColor(float r, float g, float b, float a);

		static void OnWindowResize(uint32_t width, uint32_t height);

		static void DrawIndexed(uint32_t count, bool depthTest = true);

		static void Init();

		static const Scope<ShaderLibrary>& GetShaderLibrary() { return m_ShaderLibrary; }

	private:
		static Scope<ShaderLibrary> m_ShaderLibrary;
	};
}