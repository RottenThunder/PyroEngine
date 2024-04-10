#pragma once
#include "PyroEngine/Renderer/IndexBuffer.h"

namespace PyroEngine
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	private:
		uint32_t m_RendererID;
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint64_t count);
		virtual ~OpenGLIndexBuffer();
	};
}