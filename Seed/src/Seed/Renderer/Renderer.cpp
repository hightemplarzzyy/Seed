#include "Seedpch.h"
#include "Renderer.h"

namespace Seed {

	Scope<ShaderLibrary> Renderer::m_ShaderLibrary = nullptr;

	void Renderer::Init()
	{
		m_ShaderLibrary = CreateScope<ShaderLibrary>();
		RenderCommand::Init();

		GetShaderLibrary()->Load("assets/shaders/SeedPBR_Static.glsl");
		GetShaderLibrary()->Load("assets/shaders/SeedPBR_Anim.glsl");
	}

	void Renderer::Clear()
	{
		RenderCommand::Clear();
	}

	void Renderer::Clear(float r, float g, float b, float a)
	{
		RenderCommand::Clear(r, g, b, a);
	}

	void Renderer::SetClearColor(float r, float g, float b, float a)
	{
	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewport(width, height);
	}

	void Renderer::DrawIndexed(uint32_t count, bool depthTest)
	{
		RenderCommand::DrawIndexed(count, depthTest);
	}
}