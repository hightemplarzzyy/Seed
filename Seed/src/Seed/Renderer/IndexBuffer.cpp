#include "Seedpch.h"
#include "Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Seed {

	IndexBuffer* IndexBuffer::Create(unsigned int size)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::OpenGL: return new OpenGLIndexBuffer(size);
		case RendererAPIType::None: return nullptr;
		}
		return nullptr;
	}

}