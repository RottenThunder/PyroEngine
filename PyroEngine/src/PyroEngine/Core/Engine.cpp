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
	std::vector<Application*> Engine::m_Applications;

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
		for (Application* app : m_Applications)
			app->OnDetach();

		m_Applications.clear();

		glfwTerminate();

		Logger::Terminate();
	}

	void Engine::AddApplication(Application* app)
	{
		m_Applications.push_back(app);
		app->OnAttach();
	}

	void Engine::RemoveApplication(Application* app)
	{
		auto it = std::find(m_Applications.begin(), m_Applications.end(), app);
		if (it != m_Applications.end())
		{
			app->OnDetach();
			m_Applications.erase(it);
		}
	}

	void Engine::Run()
	{
		while (m_Running)
		{
			for (Application* app : m_Applications)
			{
				app->OnUpdate();
			}
		}
	}

	void Engine::StopRunning()
	{
		m_Running = false;
	}
}