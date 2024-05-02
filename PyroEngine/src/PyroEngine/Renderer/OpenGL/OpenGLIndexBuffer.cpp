#include "PyroEnginePCH.h"
#include "OpenGLIndexBuffer.h"
#include "glad/glad.h"

namespace PyroEngine
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint64_t count)
	{
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_DYNAMIC_DRAW);

		m_Count = count;
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}
}