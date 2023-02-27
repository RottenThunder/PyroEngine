#include "PyroEnginePCH.h"
#include "WindowsWindow.h"

namespace PyroEngine
{
	static bool glfwInitialised = false;

	WindowsWindow::WindowsWindow(const std::string& title, uint32_t width, uint32_t height)
		: WindowObject(nullptr)
	{
		Init(title, width, height);
	}

	WindowsWindow::~WindowsWindow()
	{
		Terminate();
	}

	Window* Window::Create(const std::string& title, uint32_t width, uint32_t height)
	{
		return new WindowsWindow(title, width, height);
	}

	void WindowsWindow::Init(const std::string& title, uint32_t width, uint32_t height)
	{
		windowData.Title = title;
		windowData.Width = width;
		windowData.Height = height;

		if (!glfwInitialised)
		{
			int init = glfwInit();
			PYRO_ASSERT(init, "Could not initialise glfw!!!");

			glfwInitialised = true;
		}

		WindowObject = glfwCreateWindow(windowData.Width, windowData.Height, windowData.Title.c_str(), NULL, NULL);
		PYRO_ASSERT(WindowObject, "Window Object == NULL!!!");

		glfwMakeContextCurrent(WindowObject);
		glfwSetWindowUserPointer(WindowObject, &windowData);
		SetVSync(false);
	}

	void WindowsWindow::Terminate()
	{
		glfwDestroyWindow(WindowObject);
		glfwTerminate();
	}

	void WindowsWindow::SetVSync(bool vSync)
	{
		if (vSync)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		windowData.VSync = vSync;
	}

	bool WindowsWindow::IsVSync() const
	{
		return windowData.VSync;
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(WindowObject);
	}
}