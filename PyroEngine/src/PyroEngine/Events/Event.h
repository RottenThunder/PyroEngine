#pragma once
#include <string>

namespace PyroEngine
{
	enum EventType
	{
		EventTypeNone = 0,
		WindowClosed, WindowResized, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	class Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual std::string GetName() const = 0;
	};
}