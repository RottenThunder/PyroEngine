#pragma once
#include <stdint.h>
#include <cstring>

namespace PyroEngine
{
	struct Buffer
	{
		uint8_t* Data = nullptr;
		size_t Size = 0;

		Buffer() = default;
		Buffer(const Buffer&) = default;
		Buffer(size_t size)
			: Data(new uint8_t[size]), Size(size) {}

		void Allocate(size_t size)
		{
			delete[] Data;
			Data = new uint8_t[size];
			Size = size;
		}

		void Delete()
		{
			delete[] Data;
			Data = nullptr;
			Size = 0;
		}

		template<typename T>
		T* As()
		{
			return (T*)Data;
		}

		void CopyFrom(Buffer& other)
		{
			Allocate(other.Size);
			std::memcpy(Data, other.Data, other.Size);
		}

		void CopyInto(Buffer& other)
		{
			other.Allocate(Size);
			std::memcpy(other.Data, Data, Size);
		}

		operator bool() const
		{
			return (bool)Data;
		}
	};

	class ScopedBuffer
	{
	private:
		Buffer m_Buffer;
	public:
		ScopedBuffer(Buffer buffer)
			: m_Buffer(buffer) {}

		ScopedBuffer(size_t size)
			: m_Buffer(size) {}

		~ScopedBuffer() { m_Buffer.Delete(); }

		uint8_t* Data() { return m_Buffer.Data; }
		size_t Size() { return m_Buffer.Size; }

		template<typename T>
		T* As() { return m_Buffer.As<T>(); }

		operator bool() const { return m_Buffer; }
	};
}