#include "PyroEnginePCH.h"
#include "IndexBuffer.h"
#include "PyroEngine/Core/GlobalSettings.h"
#include "OpenGL/OpenGLIndexBuffer.h"

namespace PyroEngine
{
	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint64_t count)
	{
		switch (GlobalSettings::s_GraphicsAPI)
		{
		case GraphicsAPINone:
			Logger::Log(LoggerChannel::Error, "An Index Buffer has been created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLIndexBuffer(indices, count);
		default:
			break;
		}

		Logger::Log(LoggerChannel::Error, "An Index Buffer has been created with an unknown Graphics API");
		return nullptr;
	}
}