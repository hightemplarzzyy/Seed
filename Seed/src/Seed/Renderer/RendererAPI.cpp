#include "Seedpch.h"

#include "RendererAPI.h"
#include "Seed/Core/Application.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Seed {

	 RendererAPI* RendererAPI::Create()
	{
		switch (Application::APIType())
		{
			case 0:
				SEED_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
				return nullptr;
			case 1:
				RendererAPI::Current() = RendererAPIType::OpenGL;
				return new OpenGLRendererAPI();
		}

		SEED_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}