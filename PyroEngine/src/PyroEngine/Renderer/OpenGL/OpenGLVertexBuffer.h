#pragma once
#include "PyroEngine/Renderer/VertexBuffer.h"

namespace PyroEngine
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	private:
		uint32_t m_RendererID;
	public:
		OpenGLVertexBuffer(double* vertices, uint64_t size);
		virtual ~OpenGLVertexBuffer();
	};
}