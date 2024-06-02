#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace PyroEngine
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual PYRO_TYPE_ERROR AddVertexBuffer(VertexBuffer* vertexBuffer) = 0;
		virtual void SetIndexBuffer(IndexBuffer* indexBuffer) = 0;

		virtual std::vector<VertexBuffer*> GetVertexBuffers() const = 0;
		virtual IndexBuffer* GetIndexBuffer() const = 0;

		static VertexArray* Create();
	};
}