#pragma once
#include "PyroEngine/Core/Core.h"
#include "PyroEngine/Maths/Vector.h"
#include "PyroEngine/Maths/Matrix.h"

namespace PyroEngine
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void UploadUniformInt(const std::string& name, int value) = 0;
		virtual void UploadUniformIntArray(const std::string& name, int* values, uint64_t count) = 0;
		virtual void UploadUniformFloat(const std::string& name, float value) = 0;
		virtual void UploadUniformFloatArray(const std::string& name, float* values, uint64_t count) = 0;
		virtual void UploadUniformVector2(const std::string& name, const Vector2& vector) = 0;
		virtual void UploadUniformVector3(const std::string& name, const Vector3& vector) = 0;
		virtual void UploadUniformVector4(const std::string& name, const Vector4& vector) = 0;
		virtual void UploadUniformMatrix4x4(const std::string& name, const Matrix4x4& matrix) = 0;

		static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};
}