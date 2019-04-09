#include "Seedpch.h"
#include "OpenGLTexture.h"

#include <glad/glad.h>

namespace Seed {

	static GLenum SeedToOpenGLTextureFormat(TextureFormat format)
	{
		switch (format)
		{
		case TextureFormat::RGB: return GL_RGB;
		case TextureFormat::RGBA: return GL_RGBA;
		}
		return 0;
	}

	OpenGLTexture2D::OpenGLTexture2D(TextureFormat format, unsigned int width, unsigned int height)
		:m_Format(format),m_Width(width),m_Height(height)
	{
		auto self = this;
		SEED_RENDER_1(self, {
			glGenTextures(1, &self->m_RendereID);
			glBindTexture(GL_TEXTURE_2D, self->m_RendereID);
			glTexImage2D(GL_TEXTURE_2D, 0, SeedToOpenGLTextureFormat(self->m_Format), self->m_Width, self->m_Height, 0, SeedToOpenGLTextureFormat(self->m_Format), GL_UNSIGNED_BYTE, nullptr);
			glBindTexture(GL_TEXTURE_2D, 0);
		});
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		auto self = this;
		SEED_RENDER_1(self, {
			glDeleteTextures(1, &self->m_RendereID);
		});
	}
}