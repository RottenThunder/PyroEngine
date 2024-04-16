#include "PyroEnginePCH.h"
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"
#include "glad/glad.h"

namespace PyroEngine
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::AddVertexBuffer(VertexBuffer* vertexBuffer)
	{
		glBindVertexArray(m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, ((OpenGLVertexBuffer*)vertexBuffer)->GetRendererID());

		//Do OpenGL calls to configure the layout of the buffers

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(IndexBuffer* indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ((OpenGLIndexBuffer*)indexBuffer)->GetRendererID());
		m_IndexBuffer = indexBuffer;
	}
}