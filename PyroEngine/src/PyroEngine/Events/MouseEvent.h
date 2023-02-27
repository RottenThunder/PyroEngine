#pragma once
#include "Event.h"

namespace PyroEngine
{
	class MouseMovedEvent : public Event
	{
	private:
		double m_MouseX, m_MouseY;
	public:
		MouseMovedEvent(double mouseX, double mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		inline double GetX() const { return m_MouseX; }
		inline double GetY() const { return m_MouseY; }

		virtual EventType GetEventType() const override { return EventType::MouseMoved; }
		virtual uint32_t GetCategoryFlags() const override { return (uint32_t)EventCategory::Input | (uint32_t)EventCategory::Mouse; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[PYRO]: MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseMoved; }
	};

	class MouseScrolledEvent : public Event
	{
	private:
		double m_XOffset, m_YOffset;
	public:
		MouseScrolledEvent(double xOffset, double yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline double GetXOffset() const { return m_XOffset; }
		inline double GetYOffset() const { return m_YOffset; }

		virtual EventType GetEventType() const override { return EventType::MouseScrolled; }
		virtual uint32_t GetCategoryFlags() const override { return (uint32_t)EventCategory::Input | (uint32_t)EventCategory::Mouse; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[PYRO]: MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseScrolled; }
	};

	class MouseButtonEvent : public Event
	{
	protected:
		uint32_t m_Button;

		MouseButtonEvent(uint32_t button)
			: m_Button(button) {}
	public:
		inline uint32_t GetMouseButton() const { return m_Button; }

		virtual uint32_t GetCategoryFlags() const override { return (uint32_t)EventCategory::Input | (uint32_t)EventCategory::MouseButton; }
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(uint32_t button)
			: MouseButtonEvent(button) {}

		virtual EventType GetEventType() const override { return EventType::MouseButtonPressed; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[PYRO]: MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::MouseButtonPressed; }
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(uint32_t button)
			: MouseButtonEvent(button) {}

		virtual EventType GetEventType() const override { return EventType::MouseButtonReleased; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[PYRO]: MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::MouseButtonReleased; }
	};
}