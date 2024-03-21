#pragma once
#include "PyroEngine/Events/Event.h"

namespace PyroEngine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate();
		virtual void OnEvent(Event& e);
	};
}