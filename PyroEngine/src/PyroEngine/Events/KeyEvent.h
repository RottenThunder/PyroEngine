#pragma once
#include "Event.h"

namespace PyroEngine
{
	class KeyPressedEvent : public Event
	{
	private:
		int m_KeyCode;
	public:
		KeyPressedEvent(int keyCode)
			: m_KeyCode(keyCode) {}

		inline int GetKeyCode() const { return m_KeyCode; }

		virtual EventType GetEventType() const override { return EventType::KeyPressed; }
		virtual std::string GetName() const override { return "KeyPressedEvent(" + std::to_string(m_KeyCode) + ")"; }
	};

	class KeyReleasedEvent : public Event
	{
	private:
		int m_KeyCode;
	public:
		KeyReleasedEvent(int keyCode)
			: m_KeyCode(keyCode) {}

		inline int GetKeyCode() const { return m_KeyCode; }

		virtual EventType GetEventType() const override { return EventType::KeyReleased; }
		virtual std::string GetName() const override { return "KeyReleasedEvent(" + std::to_string(m_KeyCode) + ")"; }
	};
}