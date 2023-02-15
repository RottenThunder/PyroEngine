#pragma once
#include "Event.h"

namespace PyroEngine
{
	class KeyEvent : public Event
	{
	protected:
		uint32_t m_KeyCode;

		KeyEvent(uint32_t keyCode)
			: m_KeyCode(keyCode) {}
	public:
		inline uint32_t GetKeyCode() const { return m_KeyCode; }

		virtual uint32_t GetCategoryFlags() const override { return EventCategory::Input | EventCategory::Key; }
	};

	class KeyPressedEvent : public KeyEvent
	{
	private:
		uint64_t m_RepeatCount;
	public:
		KeyPressedEvent(uint32_t keyCode, uint64_t repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline uint64_t GetRepeatCount() const { return m_RepeatCount; }

		virtual EventType GetEventType() const override { return EventType::KeyPressed; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[PYRO]: KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::KeyPressed; }
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(uint32_t keyCode)
			: KeyEvent(keyCode) {}

		virtual EventType GetEventType() const override { return EventType::KeyReleased; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[PYRO]: KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::KeyPressed; }
	};
}