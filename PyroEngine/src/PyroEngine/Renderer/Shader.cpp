#include "PyroEnginePCH.h"
#include "Shader.h"
#include "PyroEngine/Core/Engine.h"
#include "OpenGL/OpenGLShader.h"

namespace PyroEngine
{
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Engine::GetGlobalSettings().globalAPI)
		{
		case GraphicsAPINone:
			PYRO_ASSERT(false, "A Shader is about to be created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLShader(vertexSrc, fragmentSrc);
		default:
			break;
		}

		PYRO_ASSERT(false, "A Shader is about to be created with an unknown Graphics API");
		return nullptr;
	}
}