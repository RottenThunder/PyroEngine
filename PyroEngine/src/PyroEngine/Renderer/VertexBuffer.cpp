#include "PyroEnginePCH.h"
#include "VertexBuffer.h"
#include "PyroEngine/Core/GlobalSettings.h"
#include "OpenGL/OpenGLVertexBuffer.h"

namespace PyroEngine
{
	VertexBuffer* VertexBuffer::Create(uint64_t size, float* vertices)
	{
		switch (GlobalSettings::s_GraphicsAPI)
		{
		case GraphicsAPINone:
			Logger::Log(LoggerChannel::Error, "A Vertex Buffer has been created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLVertexBuffer(size, vertices);
		default:
			break;
		}

		Logger::Log(LoggerChannel::Error, "A Vertex Buffer has been created with an unknown Graphics API");
		return nullptr;
	}
}