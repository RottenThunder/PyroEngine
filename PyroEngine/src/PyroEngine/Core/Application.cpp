#include "PyroEnginePCH.h"
#include "Application.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PyroEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Welcome To PyroEngine!" << std::endl;

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

		while (!glfwWindowShouldClose(WindowObject))
		{
			glfwPollEvents();
			glfwSwapBuffers(WindowObject);
		}

		glfwDestroyWindow(WindowObject);
		glfwTerminate();
	}
}