#pragma once
#include "PyroEnginePCH.h"
#include "PyroEngine/Core/Base.h"

namespace PyroEngine
{
	enum class EventType : uint32_t
	{
		None = 0,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		WindowClose, WindowResize, WindowMoved
	};

	enum EventCategory : uint32_t
	{
		None = 0,
		Input = PYRO_BIT_FIELD(0),
		Key = PYRO_BIT_FIELD(1),
		Mouse = PYRO_BIT_FIELD(2),
		MouseButton = PYRO_BIT_FIELD(3),
		Window = PYRO_BIT_FIELD(4)
	};

	class Event
	{
	private:
		friend class EventDispatcher;
	protected:
		bool m_Handled = false;
	public:
		virtual EventType GetEventType() const = 0;
		virtual uint32_t GetCategoryFlags() const = 0;
		virtual std::string GetName() const = 0;

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
	private:
		Event& m_Event;
	public:
		EventDispatcher(Event& e)
			: m_Event(e) {}

		template<typename T>
		void Dispatch(std::function<bool(T&)> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
				m_Event.m_Handled = func(*(T*)&m_Event);
		}
	};
}