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
			PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_11_DESC, PYRO_ERROR_11);
			return nullptr;
		case OpenGL:
			return new OpenGLVertexArray();
		default:
			break;
		}

		PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_12_DESC, PYRO_ERROR_12);
		return nullptr;
	}
}