#include "PyroEnginePCH.h"
#include "Engine.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PyroEngine
{
	bool Engine::m_Running = true;
	std::vector<Application*> Engine::m_Applications;
	GlobalSettings Engine::m_Settings;

	void Engine::Init()
	{
		int init = glfwInit();
		PYRO_ASSERT(init == GLFW_TRUE, "GLFW did not initialise");
	}

	void Engine::Terminate()
	{
		for (Application* app : m_Applications)
			app->OnDetach();

		m_Applications.clear();

		glfwTerminate();
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

	GlobalSettings& Engine::GetGlobalSettings()
	{
		return m_Settings;
	}
}