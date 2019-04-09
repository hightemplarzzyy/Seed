#pragma once

#include "Seed/Core/Core.h"
#include "Renderer.h"

#include <glm/glm.hpp>

namespace Seed {

	struct SEED_API ShaderUniform
	{

	};

	struct SEED_API ShaderUniformCollection
	{

	};

	enum class SEED_API UniformType
	{
		None = 0,
		Float, Float2, Float3, Float4,
		Matrix3x3, Matrix4x4,
		Int32, Uint32
	};

	struct SEED_API UniformDecl
	{
		UniformType Type;
		std::ptrdiff_t Offset;
		std::string Name;
	};

	struct UniformBufferBase
	{
		virtual const byte* GetBuffer() const = 0;
		virtual const UniformDecl* GetUniforms() const = 0;
		virtual unsigned int GetUniformCount() const = 0;
	};

	template<unsigned int N, unsigned int U>
	struct UniformBufferDeclaration : public UniformBufferBase
	{
		byte Buffer[N];
		UniformDecl Uniforms[U];
		std::ptrdiff_t Cursor = 0;

		virtual const byte* GetBuffer() const override { return Buffer; };
		virtual const UniformDecl* GetUniforms() const override { return Uniforms; };
		virtual unsigned int GetUniformCount() const override { return U; };

		template<typename T>
		void Push(const std::string& name, const T& data){}

		template<>
		void Push(const std::string& name, const float& data)
		{
			Uniforms[0] = { UniformType::Float, Cursor, name };
			memcpy(Buffer + Cursor, &data, sizeof(float));
			Cursor += sizeof(float);
		}

		template<>
		void Push(const std::string& name, const glm::vec4& data)
		{
			Uniforms[0] = { UniformType::Float4, Cursor, name };
			memcpy(Buffer + Cursor, glm::value_ptr(data), sizeof(glm::vec4));
			Cursor += sizeof(glm::vec4);
		}
	};

	class SEED_API Shader
	{
	public:
		virtual void Bind() = 0;
		virtual void UploadUniformBuffer(const UniformBufferBase& uniformBuffer) = 0;

		// Represents a complete shader program stored in a single file.
		// Note: currently for simplicity this is simply a string filepath, however
		//       in the future this will be an asset object + metadata
		static Shader* Create(const std::string& filepath);
	};
}