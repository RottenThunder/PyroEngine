#include "PyroEnginePCH.h"
#include "WindowApplication.h"
#include "glad/glad.h"

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

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(((OpenGLShader*)p_Shader)->GetRendererID());
		glBindVertexArray(((OpenGLVertexArray*)p_VertexArray)->GetRendererID());
		glDrawElements(GL_TRIANGLES, p_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

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