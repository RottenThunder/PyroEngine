#include "PyroEnginePCH.h"
#include "OpenGLShader.h"
#include "glad/glad.h"

namespace PyroEngine
{
	OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		std::unordered_map<GLenum, std::string> sources;
		sources[GL_VERTEX_SHADER] = vertexSrc;
		sources[GL_FRAGMENT_SHADER] = fragmentSrc;
		Compile(sources);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(RendererID);
	}

	void OpenGLShader::Compile(const std::unordered_map<uint32_t, std::string>& shaderSources)
	{
		GLuint program = glCreateProgram();
		std::vector<GLenum> glShaderIDs;

		for (auto& kv : shaderSources)
		{
			GLenum type = kv.first;
			const std::string& source = kv.second;

			GLuint shader = glCreateShader(type);

			const GLchar* sourceCStr = source.c_str();
			glShaderSource(shader, 1, &sourceCStr, 0);

			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::string infoLog(maxLength, '\0');
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteProgram(program);

				for (auto id : glShaderIDs)
					glDeleteShader(id);

				Logger::Log(LoggerChannel::Error, "Failed to Compile Shader: {}", infoLog);
				return;
			}

			glAttachShader(program, shader);
			glShaderIDs.push_back(shader);
		}

		glLinkProgram(program);

		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			std::string infoLog(maxLength, '\0');
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			glDeleteProgram(program);

			for (auto id : glShaderIDs)
				glDeleteShader(id);

			Logger::Log(LoggerChannel::Error, "Failed to Link Shaders: {}", infoLog);
			return;
		}

		for (auto id : glShaderIDs)
			glDetachShader(program, id);

		RendererID = program;
	}

	void OpenGLShader::UploadUniformInt(const std::string& name, int value)
	{
		glUseProgram(RendererID);
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform1i(location, value);
	}

	void OpenGLShader::UploadUniformIntArray(const std::string& name, int* values, uint64_t count)
	{
		glUseProgram(RendererID);
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform1iv(location, count, values);
	}

	void OpenGLShader::UploadUniformFloat(const std::string& name, float value)
	{
		glUseProgram(RendererID);
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform1f(location, value);
	}

	void OpenGLShader::UploadUniformFloatArray(const std::string& name, float* values, uint64_t count)
	{
		glUseProgram(RendererID);
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform1fv(location, count, values);
	}

	void OpenGLShader::UploadUniformVector2(const std::string& name, const Vector2& vector)
	{
		glUseProgram(RendererID);
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform2f(location, vector.x, vector.y);
	}

	void OpenGLShader::UploadUniformVector3(const std::string& name, const Vector3& vector)
	{
		glUseProgram(RendererID);
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform3f(location, vector.x, vector.y, vector.z);
	}

	void OpenGLShader::UploadUniformVector4(const std::string& name, const Vector4& vector)
	{
		glUseProgram(RendererID);
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
	}

	void OpenGLShader::UploadUniformMatrix4x4(const std::string& name, const Matrix4x4& matrix)
	{
		glUseProgram(RendererID);
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, &matrix.components[0]);
	}
}