#include "PyroEnginePCH.h"
#include "IndexBuffer.h"
#include "PyroEngine/Core/Engine.h"
#include "OpenGL/OpenGLIndexBuffer.h"

namespace PyroEngine
{
	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint64_t count)
	{
		switch (Engine::GetGlobalSettings().globalAPI)
		{
		case GraphicsAPINone:
			PYRO_ASSERT(false, "An Index Buffer is about to be created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLIndexBuffer(indices, count);
		default:
			break;
		}

		PYRO_ASSERT(false, "An Index Buffer is about to be created with an unknown Graphics API");
		return nullptr;
	}
}