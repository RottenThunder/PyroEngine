#pragma once
#include "PyroEngine/Maths/Vector.h"
#include "PyroEngine/Maths/Matrix.h"

namespace PyroEngine
{
	class Camera
	{
	private:
		Matrix4x4 m_ViewProjectionMatrix;
		Vector2 m_Position;
		float m_Rotation;
		float m_AspectRatio; //(Screen Width / Screen Height)
		float m_Zoom;
	public:
		Camera(float aspectRatio = 1.0f);

		const Matrix4x4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
		const Vector2& GetPosition() const { return m_Position; }
		float GetRotation() const { return m_Rotation; }
		float GetAspectRatio() const { return m_AspectRatio; }
		float GetZoom() const { return m_Zoom; }

		void Set(const Vector2& pos, float radians, float aspectRatio, float zoom);

		void SetPosition(const Vector2& pos);
		void SetRotation(float radians);
		void SetAspectRatio(float aspectRatio);
		void SetZoom(float zoom);

	};
}