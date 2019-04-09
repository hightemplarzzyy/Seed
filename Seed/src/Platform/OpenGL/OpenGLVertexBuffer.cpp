#include "Seedpch.h"
#include "OpenGLVertexBuffer.h"

#include <glad/glad.h>

namespace Seed {

	OpenGLVertexBuffer::OpenGLVertexBuffer()
	{
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(unsigned int size)
		:m_RendererID(0),m_Size(size)
	{
		SEED_RENDER_S({
			glGenBuffers(1,&self->m_RendererID);
		});
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		SEED_RENDER_S({
			glDeleteBuffers(1,&self->m_RendererID);
		});
	}

	void OpenGLVertexBuffer::SetData(void* buffer, unsigned int size, unsigned int offset)
	{
		SEED_RENDER_S3(buffer, size, offset,{
			glBindBuffer(GL_ARRAY_BUFFER, self->m_RendererID);
			glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
		});
	}

	void OpenGLVertexBuffer::Bind() const
	{
		SEED_RENDER_S({
			glBindBuffer(GL_ARRAY_BUFFER, self->m_RendererID);
		});
	}
}