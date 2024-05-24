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
			PYRO_ASSERT(false, "A Vertex Array is about to be created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLVertexArray();
		default:
			break;
		}

		PYRO_ASSERT(false, "A Vertex Array is about to be created with an unknown Graphics API");
		return nullptr;
	}
}