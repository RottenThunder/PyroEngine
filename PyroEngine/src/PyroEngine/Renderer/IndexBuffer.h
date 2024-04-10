#pragma once
#include "PyroEngine/Core/Core.h"

namespace PyroEngine
{
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		static IndexBuffer* Create(uint32_t* indices, uint64_t count);
	};
}