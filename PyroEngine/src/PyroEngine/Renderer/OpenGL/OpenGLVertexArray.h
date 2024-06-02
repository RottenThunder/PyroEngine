#pragma once
#include "PyroEngine/Renderer/VertexArray.h"

namespace PyroEngine
{
	class OpenGLVertexArray : public VertexArray
	{
	private:
		uint32_t m_RendererID;
		std::vector<VertexBuffer*> m_VertexBuffers;
		IndexBuffer* m_IndexBuffer;
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual PYRO_TYPE_ERROR AddVertexBuffer(VertexBuffer* vertexBuffer) override;
		virtual void SetIndexBuffer(IndexBuffer* indexBuffer) override;

		virtual std::vector<VertexBuffer*> GetVertexBuffers() const override { return m_VertexBuffers; }
		virtual IndexBuffer* GetIndexBuffer() const override { return m_IndexBuffer; }

		uint32_t GetRendererID() const { return m_RendererID; }
	};
}