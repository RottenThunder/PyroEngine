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
			Logger::Log(LoggerChannel::Error, "A Shader has been created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLShader(vertexSrc, fragmentSrc);
		default:
			break;
		}

		Logger::Log(LoggerChannel::Error, "A Shader has been created with an unknown Graphics API");
		return nullptr;
	}
}