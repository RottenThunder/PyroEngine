#include "PyroEnginePCH.h"
#include "VertexArray.h"
#include "PyroEngine/Core/GlobalSettings.h"
#include "OpenGL/OpenGLVertexArray.h"

namespace PyroEngine
{
	VertexArray* VertexArray::Create()
	{
		switch (GlobalSettings::s_GraphicsAPI)
		{
		case GraphicsAPINone:
			Logger::Log(LoggerChannel::Error, "A Vertex Array has been created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLVertexArray();
		default:
			break;
		}

		Logger::Log(LoggerChannel::Error, "A Vertex Array has been created with an unknown Graphics API");
		return nullptr;
	}
}