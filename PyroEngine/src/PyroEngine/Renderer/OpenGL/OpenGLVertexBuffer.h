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
		OpenGLVertexBuffer(uint64_t size, float* vertices = nullptr);
		virtual ~OpenGLVertexBuffer();

		virtual const VertexBufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const VertexBufferLayout& layout) override { m_Layout = layout; }

		virtual void SetData(const void* data, uint64_t size) override;

		uint32_t GetRendererID() const { return m_RendererID; }
	};
}