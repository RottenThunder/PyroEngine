#include "PyroEnginePCH.h"
#include "Camera.h"

namespace PyroEngine
{
	Camera::Camera(float aspectRatio)
		: m_Position({ 0.0f, 0.0f }), m_Rotation(0.0f), m_AspectRatio(aspectRatio), m_Zoom(1.0f)
	{
		m_ViewProjectionMatrix = CreateViewProjectionWithWidthAndHeight(m_AspectRatio / m_Zoom, 1.0f / m_Zoom, m_Position.x, m_Position.y, m_Rotation);
	}

	void Camera::Set(const Vector2& pos, float radians, float aspectRatio, float zoom)
	{
		m_Position = pos;
		m_Rotation = radians;
		m_AspectRatio = aspectRatio;
		m_Zoom = zoom;
		m_ViewProjectionMatrix = CreateViewProjectionWithWidthAndHeight(m_AspectRatio / m_Zoom, 1.0f / m_Zoom, m_Position.x, m_Position.y, m_Rotation);
	}

	void Camera::SetPosition(const Vector2& pos)
	{
		m_Position = pos;
		m_ViewProjectionMatrix = CreateViewProjectionWithWidthAndHeight(m_AspectRatio / m_Zoom, 1.0f / m_Zoom, m_Position.x, m_Position.y, m_Rotation);
	}

	void Camera::SetRotation(float radians)
	{
		m_Rotation = radians;
		m_ViewProjectionMatrix = CreateViewProjectionWithWidthAndHeight(m_AspectRatio / m_Zoom, 1.0f / m_Zoom, m_Position.x, m_Position.y, m_Rotation);
	}

	void Camera::SetAspectRatio(float aspectRatio)
	{
		m_AspectRatio = aspectRatio;
		m_ViewProjectionMatrix = CreateViewProjectionWithWidthAndHeight(m_AspectRatio / m_Zoom, 1.0f / m_Zoom, m_Position.x, m_Position.y, m_Rotation);
	}

	void Camera::SetZoom(float zoom)
	{
		m_Zoom = zoom;
		m_ViewProjectionMatrix = CreateViewProjectionWithWidthAndHeight(m_AspectRatio / m_Zoom, 1.0f / m_Zoom, m_Position.x, m_Position.y, m_Rotation);
	}
}