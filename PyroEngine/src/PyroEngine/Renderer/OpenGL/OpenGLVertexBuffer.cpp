#include "PyroEnginePCH.h"
#include "OpenGLVertexBuffer.h"
#include "glad/glad.h"

namespace PyroEngine
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint64_t size)
	{
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}
}