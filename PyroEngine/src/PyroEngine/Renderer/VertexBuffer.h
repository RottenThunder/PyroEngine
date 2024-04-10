#pragma once
#include "PyroEngine/Core/Core.h"

namespace PyroEngine
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		static VertexBuffer* Create(double* vertices, uint64_t size);
	};
}