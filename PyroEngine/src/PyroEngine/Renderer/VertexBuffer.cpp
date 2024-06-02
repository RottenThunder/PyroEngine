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
			PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_13_DESC, PYRO_ERROR_13);
			return nullptr;
		case OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		default:
			break;
		}

		PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_14_DESC, PYRO_ERROR_14);
		return nullptr;
	}
}