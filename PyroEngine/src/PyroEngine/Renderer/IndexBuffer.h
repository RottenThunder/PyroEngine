#pragma once
#include "PyroEngine/Core/Core.h"

namespace PyroEngine
{
	class IndexBuffer
	{
	protected:
		uint64_t m_Count;
	public:
		virtual ~IndexBuffer() {}

		uint64_t GetCount() const { return m_Count; }

		static IndexBuffer* Create(uint32_t* indices, uint64_t count);
	};
}