#include "PyroEnginePCH.h"
#include "VertexBuffer.h"
#include "PyroEngine/Core/GlobalSettings.h"
#include "OpenGL/OpenGLVertexBuffer.h"

namespace PyroEngine
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint64_t size)
	{
		switch (GlobalSettings::s_GraphicsAPI)
		{
		case GraphicsAPINone:
			PYRO_ASSERT(false, "A Vertex Buffer is about to be created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		default:
			break;
		}

		PYRO_ASSERT(false, "A Vertex Buffer is about to be created with an unknown Graphics API");
		return nullptr;
	}
}