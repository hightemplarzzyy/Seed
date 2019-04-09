#include "Seedpch.h"
#include "Shader.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace Seed {

	Shader* Shader::Create(const std::string& filepath)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::OpenGL: return new OpenGLShader(filepath);
		case RendererAPIType::None: return nullptr;
		}
		return nullptr;
	}

}