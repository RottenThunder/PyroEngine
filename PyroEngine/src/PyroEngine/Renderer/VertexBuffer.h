#pragma once
#include "VertexBufferLayout.h"

namespace PyroEngine
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual const VertexBufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const VertexBufferLayout& layout) = 0;

		static VertexBuffer* Create(double* vertices, uint64_t size);
	};
}