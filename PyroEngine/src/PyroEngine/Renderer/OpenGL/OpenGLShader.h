#pragma once
#include "PyroEngine/Renderer/Shader.h"

namespace PyroEngine
{
	class OpenGLShader : public Shader
	{
	private:
		uint32_t RendererID;
		void Compile(const std::unordered_map<uint32_t, std::string>& shaderSources);
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		uint32_t GetRendererID() const { return RendererID; }

		virtual void UploadUniformInt(const std::string& name, int value) override;
		virtual void UploadUniformIntArray(const std::string& name, int* values, uint64_t count) override;
		virtual void UploadUniformFloat(const std::string& name, float value) override;
		virtual void UploadUniformFloatArray(const std::string& name, float* values, uint64_t count) override;
		virtual void UploadUniformVector2(const std::string& name, const Vector2& vector) override;
		virtual void UploadUniformVector3(const std::string& name, const Vector3& vector) override;
		virtual void UploadUniformVector4(const std::string& name, const Vector4& vector) override;
		virtual void UploadUniformMatrix4x4(const std::string& name, const Matrix4x4& matrix) override;
	};
}