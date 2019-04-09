#include "Seedpch.h"
#include "OpenGLShader.h"

namespace Seed {

	OpenGLShader::OpenGLShader(const std::string& filepath)
	{
		ReadShaderFromFile(filepath);
		SEED_RENDER_S({
			self->CompileAndUploadShader();
		});
	}

	void OpenGLShader::Bind()
	{
		SEED_RENDER_S({
			glUseProgram(self->m_RendererID);
		});
	}

	void OpenGLShader::ReadShaderFromFile(const std::string& filepath)
	{
		std::ifstream in(filepath, std::ios::in | std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			m_ShaderSource.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&m_ShaderSource[0], m_ShaderSource.size());
			in.close();
		}
		else
		{
			SEED_CORE_WARN("Could not read shader file {0}", filepath);
		}
	}

	GLenum OpenGLShader::ShaderTypeFromString(const std::string& type)
	{
		if (type == "vertex")
			return GL_VERTEX_SHADER;
		if (type == "fragment" || type == "pixel")
			return GL_FRAGMENT_SHADER;
		return GL_NONE;
	}

	void OpenGLShader::CompileAndUploadShader()
	{
		std::unordered_map<GLenum, std::string> shaderSources;

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = m_ShaderSource.find(typeToken, 0);
		while (pos != std::string::npos)
		{
			size_t eol = m_ShaderSource.find_first_of("\r\n", pos);
			SEED_CORE_ASSERT(eol != std::string::npos, "Syntax error");
			size_t begin = pos + typeTokenLength + 1;
			std::string type = m_ShaderSource.substr(begin, eol - begin);
			SEED_CORE_ASSERT(type == "vertex" || type == "fragment" || type == "pixel", "Invalid shader type specified");

			size_t nextLinePos = m_ShaderSource.find_first_not_of("\r\n", eol);
			pos = m_ShaderSource.find(typeToken, nextLinePos);
			shaderSources[ShaderTypeFromString(type)] = m_ShaderSource.substr(nextLinePos, pos - (nextLinePos == std::string::npos ? m_ShaderSource.size() - 1 : nextLinePos));
		}

		std::vector<GLuint> shaderRendererIDs;

		GLuint program = glCreateProgram();
		for (auto& kv : shaderSources)
		{
			GLenum type = kv.first;
			std::string& source = kv.second;

			GLuint shaderRendererID = glCreateShader(type);
			const GLchar* sourceCstr = (const GLchar*)source.c_str();
			glShaderSource(shaderRendererID, 1, &sourceCstr, 0);

			glCompileShader(shaderRendererID);

			GLint isComplied = 0;
			glGetShaderiv(shaderRendererID, GL_COMPILE_STATUS, &isComplied);
			if (isComplied == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shaderRendererID, GL_INFO_LOG_LENGTH, &maxLength);

				// The max length includes the NULL char
				std::vector<GLchar> infolog(maxLength);
				glGetShaderInfoLog(shaderRendererID, maxLength, &maxLength, &infolog[0]);

				SEED_CORE_ERROR("Shader compilation failed :\n{0}", &infolog[0]);

				glDeleteShader(shaderRendererID);

				SEED_CORE_ASSERT(false, "Failed");
			}

			shaderRendererIDs.push_back(shaderRendererID);
			glAttachShader(program, shaderRendererID);
		}

		glLinkProgram(program);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The max length includes the NULL char
			std::vector<GLchar> infolog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infolog[0]);

			SEED_CORE_ERROR("Shader compilation failed :\n{0}", &infolog[0]);

			glDeleteProgram(program);

			// Don't leak shaders.
			for (auto id : shaderRendererIDs)
				glDeleteShader(id);
		}

		// Always detach shaders after a successful link.
		for (auto id : shaderRendererIDs)
			glDetachShader(program, id);

		m_RendererID = program;
	}

	void OpenGLShader::UploadUniformBuffer(const UniformBufferBase& uniformbuffer)
	{
		for (unsigned int i = 0; i < uniformbuffer.GetUniformCount(); i++)
		{
			const UniformDecl& decl = uniformbuffer.GetUniforms()[i];
			switch (decl.Type)
			{
				case UniformType::Float:
				{
					const std::string name = decl.Name;
					float value = *(float*)(uniformbuffer.GetBuffer() + decl.Offset);
					SEED_RENDER_S2(name, value, {
						self->UploadUniformFloat(name,value);
						});
				}
				case UniformType::Float4:
				{
					const std::string& name = decl.Name;
					glm::vec4& values = *(glm::vec4*)(uniformbuffer.GetBuffer() + decl.Offset);
					SEED_RENDER_S2(name, values, {
						self->UploadUniformFloat4(name,values);
						});
				}
			}
		}
	}

	void OpenGLShader::UploadUniformFloat(const std::string& name, float value)
	{
		glUseProgram(m_RendererID);
		glUniform1f(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}

	void OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4& values)
	{
		glUseProgram(m_RendererID);
		glUniform4f(glGetUniformLocation(m_RendererID, name.c_str()), values.x, values.y, values.z, values.w);
	}
}