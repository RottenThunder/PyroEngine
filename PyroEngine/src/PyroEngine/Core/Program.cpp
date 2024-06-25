#include "PyroEnginePCH.h"
#include "Program.h"
#include "glad/glad.h"

namespace PyroEngine
{
	void Program::OnEngineAttach()
	{
		p_Window.SetEventCallback(PYRO_BIND_EVENT_FUNCTION(Program::OnEngineEvent));

		OnProgramAttach();

		glUseProgram(((OpenGLShader*)p_Shader)->GetRendererID());
		GLint location = glGetUniformLocation(((OpenGLShader*)p_Shader)->GetRendererID(), "u_Texture");
		glUniform1i(location, 0);
	}

	void Program::OnEngineDetach()
	{
		OnProgramDetach();
	}

	void Program::OnEngineUpdate()
	{
		OnProgramUpdate();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, ((OpenGLTexture*)p_Texture)->GetRendererID());
		glUseProgram(((OpenGLShader*)p_Shader)->GetRendererID());
		glBindVertexArray(((OpenGLVertexArray*)p_VertexArray)->GetRendererID());
		glDrawElements(GL_TRIANGLES, p_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

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

	void Program::OnProgramUpdate()
	{
	}

	void Program::OnProgramEvent(Event& e)
	{
	}
}