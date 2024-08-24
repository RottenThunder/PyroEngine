#pragma once
#include "VertexBufferLayout.h"

namespace PyroEngine
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual const VertexBufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const VertexBufferLayout& layout) = 0;

		virtual void SetData(const void* data, uint64_t size) = 0;

		static VertexBuffer* Create(uint64_t size, float* vertices = nullptr);
	};
}