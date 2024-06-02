#include "PyroEnginePCH.h"
#include "Shader.h"
#include "PyroEngine/Core/GlobalSettings.h"
#include "OpenGL/OpenGLShader.h"

namespace PyroEngine
{
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (GlobalSettings::s_GraphicsAPI)
		{
		case GraphicsAPINone:
			PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_7_DESC, PYRO_ERROR_7);
			return nullptr;
		case OpenGL:
			return new OpenGLShader(vertexSrc, fragmentSrc);
		default:
			break;
		}

		PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_8_DESC, PYRO_ERROR_8);
		return nullptr;
	}
}