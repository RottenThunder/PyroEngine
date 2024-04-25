#pragma once
#include <string>
#include <vector>
#include "PyroEngine/Core/Core.h"

namespace PyroEngine
{
	enum ShaderDataType
	{
		ShaderDataTypeNone = 0, Float, Float2, Float3, Float4, Double, Double2, Double3, Double4, Int, Int2, Int3, Int4, Bool, Mat2x2f, Mat3x3f, Mat4x4f, Mat2x2d, Mat3x3d, Mat4x4d
	};

	static uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::ShaderDataTypeNone:
			return 0;
		case ShaderDataType::Float:
			return sizeof(float);
		case ShaderDataType::Float2:
			return sizeof(float) * 2;
		case ShaderDataType::Float3:
			return sizeof(float) * 3;
		case ShaderDataType::Float4:
			return sizeof(float) * 4;
		case ShaderDataType::Double:
			return sizeof(double);
		case ShaderDataType::Double2:
			return sizeof(double) * 2;
		case ShaderDataType::Double3:
			return sizeof(double) * 3;
		case ShaderDataType::Double4:
			return sizeof(double) * 4;
		case ShaderDataType::Int:
			return sizeof(int);
		case ShaderDataType::Int2:
			return sizeof(int) * 2;
		case ShaderDataType::Int3:
			return sizeof(int) * 3;
		case ShaderDataType::Int4:
			return sizeof(int) * 4;
		case ShaderDataType::Bool:
			return sizeof(bool);
		case ShaderDataType::Mat2x2f:
			return sizeof(float) * 2 * 2;
		case ShaderDataType::Mat3x3f:
			return sizeof(float) * 3 * 3;
		case ShaderDataType::Mat4x4f:
			return sizeof(float) * 4 * 4;
		case ShaderDataType::Mat2x2d:
			return sizeof(double) * 2 * 2;
		case ShaderDataType::Mat3x3d:
			return sizeof(double) * 3 * 3;
		case ShaderDataType::Mat4x4d:
			return sizeof(double) * 4 * 4;
		}

		PYRO_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	struct VertexBufferElement
	{
		std::string m_Name;
		ShaderDataType m_Type;
		uint32_t m_Size;
		uint32_t m_Offset;

		VertexBufferElement() {}
		VertexBufferElement(ShaderDataType type, const std::string& name)
			: m_Name(name), m_Type(type), m_Size(ShaderDataTypeSize(type)), m_Offset(0) {}

		uint32_t GetComponentCount() const
		{
			switch (m_Type)
			{
			case ShaderDataType::ShaderDataTypeNone:
				return 0;
			case ShaderDataType::Float:
				return 1;
			case ShaderDataType::Float2:
				return 2;
			case ShaderDataType::Float3:
				return 3;
			case ShaderDataType::Float4:
				return 4;
			case ShaderDataType::Double:
				return 1;
			case ShaderDataType::Double2:
				return 2;
			case ShaderDataType::Double3:
				return 3;
			case ShaderDataType::Double4:
				return 4;
			case ShaderDataType::Int:
				return 1;
			case ShaderDataType::Int2:
				return 2;
			case ShaderDataType::Int3:
				return 3;
			case ShaderDataType::Int4:
				return 4;
			case ShaderDataType::Bool:
				return 1;
			case ShaderDataType::Mat2x2f:
				return 2 * 2;
			case ShaderDataType::Mat3x3f:
				return 3 * 3;
			case ShaderDataType::Mat4x4f:
				return 4 * 4;
			case ShaderDataType::Mat2x2d:
				return 2 * 2;
			case ShaderDataType::Mat3x3d:
				return 3 * 3;
			case ShaderDataType::Mat4x4d:
				return 4 * 4;
			}

			PYRO_ASSERT(false, "Unknown ShaderDataType!");
			return 0;
		}
	};

	class VertexBufferLayout
	{
	private:
		std::vector<VertexBufferElement> m_Elements;
		uint32_t m_Stride;

		void CalculateOffsetsAndStride()
		{
			uint32_t offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements)
			{
				element.m_Offset = offset;
				offset += element.m_Size;
				m_Stride += element.m_Size;
			}
		}
	public:
		VertexBufferLayout() {}
		VertexBufferLayout(const std::initializer_list<VertexBufferElement>& elements)
			: m_Elements(elements)
		{
			CalculateOffsetsAndStride();
		}

		uint32_t GetStride() const { return m_Stride; }
		const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }

		std::vector<VertexBufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<VertexBufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<VertexBufferElement>::const_iterator cbegin() const { return m_Elements.cbegin(); }
		std::vector<VertexBufferElement>::const_iterator cend() const { return m_Elements.cend(); }
	};
}