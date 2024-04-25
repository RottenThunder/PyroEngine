#pragma once
#include "PyroEngine/Renderer/VertexBuffer.h"

namespace PyroEngine
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	private:
		VertexBufferLayout m_Layout;
		uint32_t m_RendererID;
	public:
		OpenGLVertexBuffer(double* vertices, uint64_t size);
		virtual ~OpenGLVertexBuffer();

		virtual const VertexBufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const VertexBufferLayout& layout) override { m_Layout = layout; }

		uint32_t GetRendererID() const { return m_RendererID; }
	};
}