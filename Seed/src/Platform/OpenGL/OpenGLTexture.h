#pragma once

#include "Seed/Renderer/Renderer.h"
#include "Seed/Renderer/RendererAPI.h"
#include "Seed/Renderer/Texture.h"

namespace Seed {

	class SEED_API OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(TextureFormat format, unsigned int width, unsigned int height);
		~OpenGLTexture2D();

		virtual TextureFormat GetFormat() const { return m_Format; };
		virtual unsigned int GetWidth() const { return m_Width; };
		virtual unsigned int GetHeight() const { return m_Height; };

	private:
		RendererID m_RendereID;
		TextureFormat m_Format;
		unsigned int m_Width, m_Height;
	};

}