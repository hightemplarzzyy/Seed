#pragma once

#include "Seed/Renderer/IndexBuffer.h"

namespace Seed {

	class SEED_API OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int size);
		virtual ~OpenGLIndexBuffer();

		virtual void SetData(void* buffer, unsigned int size, unsigned int offset = 0);
		virtual void Bind() const;

		virtual unsigned int GetSize() const { return m_Size; };
		virtual RendererID GetRendererID() const { return m_RendererID; };

	private:
		RendererID m_RendererID;
		unsigned int m_Size;
	};

}