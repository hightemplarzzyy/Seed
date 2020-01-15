#include "Seedpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Seed {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case Seed::ShaderDataType::Float:    return GL_FLOAT;
		case Seed::ShaderDataType::Float2:   return GL_FLOAT;
		case Seed::ShaderDataType::Float3:   return GL_FLOAT;
		case Seed::ShaderDataType::Float4:   return GL_FLOAT;
		case Seed::ShaderDataType::Mat3:     return GL_FLOAT;
		case Seed::ShaderDataType::Mat4:     return GL_FLOAT;
		case Seed::ShaderDataType::Int:      return GL_INT;
		case Seed::ShaderDataType::Int2:     return GL_INT;
		case Seed::ShaderDataType::Int3:     return GL_INT;
		case Seed::ShaderDataType::Int4:     return GL_INT;
		case Seed::ShaderDataType::Bool:     return GL_BOOL;
		}

		SEED_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		SEED_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		Bind();
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			auto glBaseType = ShaderDataTypeToOpenGLBaseType(element.Type);
			glEnableVertexAttribArray(m_VertexBufferIndex);
			if (glBaseType == GL_INT)
			{
				glVertexAttribIPointer(m_VertexBufferIndex,
					element.GetComponentCount(),
					glBaseType,
					layout.GetStride(),
					(const void*)(intptr_t)element.Offset);
			}
			else
			{
				glVertexAttribPointer(m_VertexBufferIndex,
					element.GetComponentCount(),
					glBaseType,
					element.Normalized ? GL_TRUE : GL_FALSE,
					layout.GetStride(),
					(const void*)(intptr_t)element.Offset);
			}
			m_VertexBufferIndex++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		Bind();
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}