#pragma once

#include "Renderer.h"

namespace Seed {

	class SEED_API VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void SetData(void* buffer, unsigned int size, unsigned int offset = 0) = 0;
		virtual void Bind() const = 0;

		virtual unsigned int GetSize() const = 0;
		virtual RendererID GetRendererID() const = 0;

		static VertexBuffer* Create(unsigned int size = 0);
	};

	class SEED_API IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {};

		virtual void SetData(void* buffer, unsigned int size, unsigned int offset = 0) = 0;
		virtual void Bind() const = 0;

		virtual uint32_t GetCount() const = 0;

		virtual unsigned int GetSize() const = 0;
		virtual RendererID GetRendererID() const = 0;

		static IndexBuffer* Create(unsigned int size = 0);
	};

}