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
			PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_5_DESC, PYRO_ERROR_5);
			return nullptr;
		case OpenGL:
			return new OpenGLIndexBuffer(indices, count);
		default:
			break;
		}

		PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_6_DESC, PYRO_ERROR_6);
		return nullptr;
	}
}