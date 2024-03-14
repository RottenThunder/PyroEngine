#pragma once
#include "Event.h"

namespace PyroEngine
{
	class WindowMovedEvent : public Event
	{
	private:
		int m_PosX, m_PosY;
	public:
		WindowMovedEvent(int posX, int posY)
			: m_PosX(posX), m_PosY(posY) {}

		inline int GetPosX() const { return m_PosX; }
		inline int GetPosY() const { return m_PosY; }

		virtual EventType GetEventType() const override { return EventType::WindowMoved; }
		virtual std::string GetName() const override { return "WindowMovedEvent(" + std::to_string(m_PosX) + ", " + std::to_string(m_PosY) + ")"; }
	};

	class WindowResizedEvent : public Event
	{
	private:
		int m_Width, m_Height;
	public:
		WindowResizedEvent(int width, int height)
			: m_Width(width), m_Height(height) {}

		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }

		virtual EventType GetEventType() const override { return EventType::WindowResized; }
		virtual std::string GetName() const override { return "WindowResizedEvent(" + std::to_string(m_Width) + ", " + std::to_string(m_Height) + ")"; }
	};

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}

		virtual EventType GetEventType() const override { return EventType::WindowClosed; }
		virtual std::string GetName() const override { return "WindowClosedEvent()"; }
	};
}