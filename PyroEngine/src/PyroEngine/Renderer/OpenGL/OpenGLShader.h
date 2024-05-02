#pragma once
#include "PyroEngine/Renderer/Shader.h"

namespace PyroEngine
{
	class OpenGLShader : public Shader
	{
	private:
		uint32_t RendererID;
		void Compile(const std::unordered_map<uint32_t, std::string>& shaderSources);
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();
	};
}