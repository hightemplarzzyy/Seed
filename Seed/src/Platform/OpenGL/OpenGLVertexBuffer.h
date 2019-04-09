#pragma once

#include "Seed/Renderer/VertexBuffer.h"

namespace Seed {

	class SEED_API OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer();
		OpenGLVertexBuffer(unsigned int size);
		virtual ~OpenGLVertexBuffer();

		virtual void SetData(void* buffer, unsigned int size, unsigned int offset = 0);
		virtual void Bind() const;

		virtual unsigned int GetSize() const { return m_Size; }
		virtual RendererID GetRendererID() const { return m_RendererID; }
	private:
		RendererID m_RendererID;
		unsigned int m_Size;
	};

}