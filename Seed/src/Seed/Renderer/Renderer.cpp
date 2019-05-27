#include "Seedpch.h"
#include "Renderer.h"

namespace Seed {

	Renderer* Renderer::s_Instance = new Renderer();
	RendererAPIType RendererAPI::s_CurrentRendererAPI = RendererAPIType::OpenGL;

	void Renderer::Init()
	{
		SEED_RENDER({ RendererAPI::Init(); });
	}

	void Renderer::Clear()
	{
	}

	void Renderer::Clear(float r, float g, float b, float a)
	{
		SEED_RENDER_4(r, g, b, a, {
			RendererAPI::Clear(r,g,b,a);
			});
	}

	void Renderer::ClearMagenta()
	{
		Clear(1, 0, 1);
	}

	void Renderer::SetClearColor(float r, float g, float b, float a)
	{
	}

	void Renderer::DrawIndexed(unsigned int count, bool depthTest)
	{
		SEED_RENDER_2(count, depthTest, {
			RendererAPI::DrawIndexed(count, depthTest);
			});
	}

	void Renderer::WaitAndRender()
	{
		s_Instance->m_CommandQueue.Execute();
	}
}