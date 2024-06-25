#include "PyroEnginePCH.h"
#include "Engine.h"
#include "ProcessorAnalyser.h"
#include "PyroEngine/Maths/MathF.h"
#include "Logger.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PyroEngine
{
	bool Engine::m_Running = true;
	std::vector<Program*> Engine::m_Programs;

	PYRO_TYPE_ERROR Engine::Init()
	{
		Logger::Init();

		int init = glfwInit();
		if (init != GLFW_TRUE)
		{
			PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_1_DESC, PYRO_ERROR_1);
			Logger::Terminate();
			return PYRO_ERROR_1;
		}

		ProcessorAnalyser::Analyse();

		MathF::Init();

		return PYRO_ERROR_NO_ERROR;
	}

	PYRO_TYPE_ERROR Engine::InitWithoutLogger()
	{
		int init = glfwInit();
		if (init != GLFW_TRUE)
			return PYRO_ERROR_1;

		ProcessorAnalyser::Analyse();

		MathF::Init();

		return PYRO_ERROR_NO_ERROR;
	}

	void Engine::Terminate()
	{
		for (Program* program : m_Programs)
			program->OnEngineDetach();

		m_Programs.clear();

		glfwTerminate();

		Logger::Terminate();
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
		while (m_Running)
		{
			for (Program* program : m_Programs)
			{
				program->OnEngineUpdate();
			}
		}
	}

	void Engine::StopRunning()
	{
		m_Running = false;
	}
}