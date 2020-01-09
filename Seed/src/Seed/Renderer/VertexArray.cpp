#include "Seedpch.h"

#include "VertexArray.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Seed {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::None:    SEED_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPIType::OpenGL:  return std::make_shared<OpenGLVertexArray>();
		}

		SEED_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}