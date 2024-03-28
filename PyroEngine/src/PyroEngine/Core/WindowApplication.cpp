#include "PyroEnginePCH.h"
#include "WindowApplication.h"

namespace PyroEngine
{
	void WindowApplication::OnAttach()
	{
		m_Window.SetEventCallback(PYRO_BIND_EVENT_FUNCTION(WindowApplication::OnEvent));

		OnWindowAttach();
	}

	void WindowApplication::OnDetach()
	{
		OnWindowDetach();
	}

	void WindowApplication::OnUpdate()
	{
		OnWindowUpdate();

		m_Window.OnUpdate();
	}

	void WindowApplication::OnEvent(Event& e)
	{
		OnWindowEvent(e);

		if (e.GetEventType() == PyroEngine::EventType::WindowClosed)
			Engine::StopRunning();
	}

	void WindowApplication::OnWindowAttach()
	{
	}

	void WindowApplication::OnWindowDetach()
	{
	}

	void WindowApplication::OnWindowUpdate()
	{
	}

	void WindowApplication::OnWindowEvent(Event& e)
	{
	}
}