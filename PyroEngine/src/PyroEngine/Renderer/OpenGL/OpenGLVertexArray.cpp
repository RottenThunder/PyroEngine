#include "PyroEnginePCH.h"
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"
#include "glad/glad.h"

namespace PyroEngine
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:
			return GL_FLOAT;
		case ShaderDataType::Float2:
			return GL_FLOAT;
		case ShaderDataType::Float3:
			return GL_FLOAT;
		case ShaderDataType::Float4:
			return GL_FLOAT;
		case ShaderDataType::Double:
			return GL_DOUBLE;
		case ShaderDataType::Double2:
			return GL_DOUBLE;
		case ShaderDataType::Double3:
			return GL_DOUBLE;
		case ShaderDataType::Double4:
			return GL_DOUBLE;
		case ShaderDataType::Int:
			return GL_INT;
		case ShaderDataType::Int2:
			return GL_INT;
		case ShaderDataType::Int3:
			return GL_INT;
		case ShaderDataType::Int4:
			return GL_INT;
		case ShaderDataType::UInt:
			return GL_UNSIGNED_INT;
		case ShaderDataType::UInt2:
			return GL_UNSIGNED_INT;
		case ShaderDataType::UInt3:
			return GL_UNSIGNED_INT;
		case ShaderDataType::UInt4:
			return GL_UNSIGNED_INT;
		case ShaderDataType::Bool:
			return GL_BOOL;
		case ShaderDataType::Mat2x2f:
			return GL_FLOAT;
		case ShaderDataType::Mat3x3f:
			return GL_FLOAT;
		case ShaderDataType::Mat4x4f:
			return GL_FLOAT;
		case ShaderDataType::Mat2x2d:
			return GL_DOUBLE;
		case ShaderDataType::Mat3x3d:
			return GL_DOUBLE;
		case ShaderDataType::Mat4x4d:
			return GL_DOUBLE;
		}

		Logger::Log(LoggerChannel::Error, "An Unknown ShaderDataType has been requested to process");
		return 0;
	}

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
		if (vertexBuffer->GetLayout().GetElements().size() == 0)
		{
			Logger::Log(LoggerChannel::Error, "A Vertex Buffer has been sent to a Vertex Array with no layout");
			return;
		}

		glBindVertexArray(m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, ((OpenGLVertexBuffer*)vertexBuffer)->GetRendererID());

		uint32_t index = 0;
		for (const auto& element : vertexBuffer->GetLayout())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, element.GetComponentCount(), ShaderDataTypeToOpenGLBaseType(element.m_Type), false, vertexBuffer->GetLayout().GetStride(), (const void*)(const uint64_t)element.m_Offset);
			index++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(IndexBuffer* indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ((OpenGLIndexBuffer*)indexBuffer)->GetRendererID());
		m_IndexBuffer = indexBuffer;
	}
}