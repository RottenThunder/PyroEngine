#include "PyroEnginePCH.h"
#include "Program.h"

namespace PyroEngine
{
	void Program::OnEngineAttach()
	{
		p_Window.SetEventCallback(PYRO_BIND_EVENT_FUNCTION(Program::OnEngineEvent));

		OnProgramAttach();
	}

	void Program::OnEngineDetach()
	{
		OnProgramDetach();
	}

	void Program::OnEngineUpdate(float deltaTime)
	{
		OnProgramUpdate(deltaTime);

		p_Window.OnUpdate();
	}

	void Program::OnEngineEvent(Event& e)
	{
		OnProgramEvent(e);

		if (e.GetEventType() == PyroEngine::EventType::WindowClosed)
			Engine::StopRunning();
	}

	void Program::OnProgramAttach()
	{
	}

	void Program::OnProgramDetach()
	{
	}

	void Program::OnProgramUpdate(float deltaTime)
	{
	}

	void Program::OnProgramEvent(Event& e)
	{
	}
}