#include "Seedpch.h"
#include "Texture.h"

#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Seed {

	Texture2D* Texture2D::Create(TextureFormat format, unsigned int width, unsigned int height)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::OpenGL: return new OpenGLTexture2D(format, width, height);
		case RendererAPIType::None: return nullptr;
		}
		return nullptr;
	}

	Texture2D* Texture2D::Create(const std::string& path, bool srgb)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::None: return nullptr;
		case RendererAPIType::OpenGL: return new OpenGLTexture2D(path, srgb);
		}
		return nullptr;
	}

	TextureCube* TextureCube::Create(const std::string& path)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::None: return nullptr;
		case RendererAPIType::OpenGL: return new OpenGLTextureCube(path);
		}
		return nullptr;
	}
}