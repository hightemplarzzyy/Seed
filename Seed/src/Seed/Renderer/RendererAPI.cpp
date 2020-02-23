#include "Seedpch.h"

#include "RendererAPI.h"
#include "Seed/Core/Application.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Seed {

	 RendererAPI* RendererAPI::Create()
	{
		if (Application::Get().RenderAPIType() == "OpenGL")
		{
			RendererAPI::Current() = RendererAPIType::OpenGL;
			return new OpenGLRendererAPI();
		}
		else if (Application::Get().RenderAPIType() == "DX11")
		{
			// TODO: D3D11
			RendererAPI::Current() = RendererAPIType::DX11;
			// return new D3D11RendererAPI;
		}
		else
		{
			SEED_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		}

		SEED_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}