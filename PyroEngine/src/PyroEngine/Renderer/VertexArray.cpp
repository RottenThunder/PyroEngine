#include "PyroEnginePCH.h"
#include "VertexArray.h"
#include "PyroEngine/Core/Engine.h"
#include "OpenGL/OpenGLVertexArray.h"

namespace PyroEngine
{
	VertexArray* VertexArray::Create()
	{
		switch (Engine::GetGlobalSettings().globalAPI)
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