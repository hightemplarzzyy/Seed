#include "Seedpch.h"
#include "Platform/OpenGL/OpenGLVertexBuffer.h"

namespace Seed {

	VertexBuffer* VertexBuffer::Create(unsigned int size)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::OpenGL: return new OpenGLVertexBuffer;
		case RendererAPIType::None: return nullptr;
		}
		return nullptr;
	}

}