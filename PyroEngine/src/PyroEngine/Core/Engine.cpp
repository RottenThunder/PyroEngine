#include "PyroEnginePCH.h"
#include "Engine.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PyroEngine
{
	bool Engine::m_Running = true;
	std::vector<Application*> Engine::m_Applications;

	void Engine::Init()
	{
		std::cout << "Welcome To PyroEngine!" << std::endl;
	}

	void Engine::Terminate()
	{
		for (Application* app : m_Applications)
			app->OnDetach();

		m_Applications.clear();
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
		int init = glfwInit();
		if (init == GLFW_FALSE)
			return;

		GLFWwindow* WindowObject = glfwCreateWindow(1280, 720, "PyroEngine", NULL, NULL);
		PYRO_ASSERT(WindowObject, "Window Object == NULL!!!");

		glfwMakeContextCurrent(WindowObject);

		int gladInit = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if (gladInit == GLFW_FALSE)
		{
			glfwTerminate();
			return;
		}

		glfwSwapInterval(0);

		while (m_Running)
		{
			glfwPollEvents();
			glfwSwapBuffers(WindowObject);

			for (Application* app : m_Applications)
			{
				app->OnUpdate();
			}

			m_Running = !glfwWindowShouldClose(WindowObject);
		}

		glfwTerminate();
	}
}