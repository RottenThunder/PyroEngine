#pragma once
#include "Event.h"

namespace PyroEngine
{
	class MouseButtonPressedEvent : public Event
	{
	private:
		int m_Button;
	public:
		MouseButtonPressedEvent(int button)
			: m_Button(button) {}

		inline int GetButton() const { return m_Button; }

		virtual EventType GetEventType() const override { return EventType::MouseButtonPressed; }
		virtual std::string GetName() const override { return "MouseButtonPressedEvent(" + std::to_string(m_Button) + ")"; }
	};

	class MouseButtonReleasedEvent : public Event
	{
	private:
		int m_Button;
	public:
		MouseButtonReleasedEvent(int button)
			: m_Button(button) {}

		inline int GetButton() const { return m_Button; }

		virtual EventType GetEventType() const override { return EventType::MouseButtonReleased; }
		virtual std::string GetName() const override { return "MouseButtonReleasedEvent(" + std::to_string(m_Button) + ")"; }
	};

	class MouseMovedEvent : public Event
	{
	private:
		double m_MouseX, m_MouseY;
	public:
		MouseMovedEvent(double mouseX, double mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		inline double GetMouseX() const { return m_MouseX; }
		inline double GetMouseY() const { return m_MouseY; }

		virtual EventType GetEventType() const override { return EventType::MouseMoved; }
		virtual std::string GetName() const override { return "MouseMovedEvent(" + std::to_string(m_MouseX) + ", " + std::to_string(m_MouseY) + ")"; }
	};

	class MouseScrolledEvent : public Event
	{
	private:
		double m_OffsetX, m_OffsetY;
	public:
		MouseScrolledEvent(double offsetX, double offsetY)
			: m_OffsetX(offsetX), m_OffsetY(offsetY) {}

		inline double GetOffsetX() const { return m_OffsetX; }
		inline double GetOffsetY() const { return m_OffsetY; }

		virtual EventType GetEventType() const override { return EventType::MouseScrolled; }
		virtual std::string GetName() const override { return "MouseScrolledEvent(" + std::to_string(m_OffsetX) + ", " + std::to_string(m_OffsetY) + ")"; }
	};
}