#pragma once
#include "Event.h"

namespace PyroEngine
{
	class WindowMovedEvent : public Event
	{
	private:
		int32_t m_PosX, m_PosY;
	public:
		WindowMovedEvent(int32_t x, int32_t y)
			: m_PosX(x), m_PosY(y) {}

		inline int32_t GetX() const { return m_PosX; }
		inline int32_t GetY() const { return m_PosY; }

		virtual EventType GetEventType() const override { return EventType::WindowMoved; }
		virtual uint32_t GetCategoryFlags() const override { return (uint32_t)EventCategory::Window; }
		virtual std::string GetDescription() const override
		{
			std::stringstream ss;
			ss << "[PYRO]: WindowMovedEvent: " << m_PosX << ", " << m_PosY;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowMoved; }
	};

	class WindowResizeEvent : public Event
	{
	private:
		uint32_t m_Width, m_Height;
	public:
		WindowResizeEvent(uint32_t width, uint32_t height)
			: m_Width(width), m_Height(height) {}

		inline uint32_t GetWidth() const { return m_Width; }
		inline uint32_t GetHeight() const { return m_Height; }

		virtual EventType GetEventType() const override { return EventType::WindowResize; }
		virtual uint32_t GetCategoryFlags() const override { return (uint32_t)EventCategory::Window; }
		virtual std::string GetDescription() const override
		{
			std::stringstream ss;
			ss << "[PYRO]: WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowResize; }
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		virtual EventType GetEventType() const override { return EventType::WindowClose; }
		virtual uint32_t GetCategoryFlags() const override { return (uint32_t)EventCategory::Window; }
		virtual std::string GetDescription() const override
		{
			std::stringstream ss;
			ss << "[PYRO]: WindowCloseEvent";
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowClose; }
	};
}