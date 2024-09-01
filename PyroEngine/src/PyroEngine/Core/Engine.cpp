#include "PyroEnginePCH.h"
#include "Engine.h"
#include "ProcessorAnalyser.h"
#include "PyroEngine/Maths/MathF.h"
#include "PyroEngine/Renderer/Renderer.h"
#include "Logger.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PyroEngine
{
	bool Engine::m_Running = true;
	std::vector<Program*> Engine::m_Programs;
	Timer Engine::m_DeltaTimer;

	void Engine::Init()
	{
		int init = glfwInit();
		if (init != GLFW_TRUE)
		{
			Logger::Log(LoggerChannel::Error, "GLFW did not initialise");
			return;
		}

		ProcessorAnalyser::Analyse();
		MathF::Init();
		//Renderer::Init(); //Not here because for opengl you need to do it at window creation
	}

	void Engine::Terminate()
	{
		for (Program* program : m_Programs)
			program->OnEngineDetach();

		m_Programs.clear();

		Renderer::Terminate();

		glfwTerminate();
	}

	void Engine::AddProgram(Program* program)
	{
		m_Programs.push_back(program);
		program->OnEngineAttach();
	}

	void Engine::RemoveProgram(Program* program)
	{
		auto it = std::find(m_Programs.begin(), m_Programs.end(), program);
		if (it != m_Programs.end())
		{
			program->OnEngineDetach();
			m_Programs.erase(it);
		}
	}

	void Engine::Run()
	{
		m_DeltaTimer.Reset();

		while (m_Running)
		{
			float deltaTime = m_DeltaTimer.GetSeconds();

			m_DeltaTimer.Reset();
			for (Program* program : m_Programs)
				program->OnEngineUpdate(deltaTime);
		}
	}

	void Engine::StopRunning()
	{
		m_Running = false;
	}
}