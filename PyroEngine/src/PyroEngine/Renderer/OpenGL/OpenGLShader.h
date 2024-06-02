#pragma once
#include "PyroEngine/Renderer/Shader.h"

namespace PyroEngine
{
	class OpenGLShader : public Shader
	{
	private:
		uint32_t RendererID;
		PYRO_TYPE_ERROR Compile(const std::unordered_map<uint32_t, std::string>& shaderSources);
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		uint32_t GetRendererID() const { return RendererID; }
	};
}