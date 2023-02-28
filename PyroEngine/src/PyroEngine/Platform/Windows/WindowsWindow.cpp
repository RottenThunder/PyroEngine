#include "PyroEnginePCH.h"
#include "WindowsWindow.h"
#include "PyroEngine/Events/KeyEvent.h"
#include "PyroEngine/Events/MouseEvent.h"
#include "PyroEngine/Events/WindowEvent.h"

namespace PyroEngine
{
	static bool glfwInitialised = false;

	static void GLFWerrorCallback(int error, const char* description)
	{
		std::cout << "[PYRO] [GLFW_ERROR(" << error << ")] " << description << std::endl;
	}

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

			glfwSetErrorCallback(GLFWerrorCallback);
			glfwInitialised = true;
		}

		WindowObject = glfwCreateWindow(windowData.Width, windowData.Height, windowData.Title.c_str(), NULL, NULL);
		PYRO_ASSERT(WindowObject, "Window Object == NULL!!!");

		glfwMakeContextCurrent(WindowObject);
		glfwSetWindowUserPointer(WindowObject, &windowData);
		SetVSync(false);

		//Setting GLFW Event Callbacks
		glfwSetWindowSizeCallback(WindowObject, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = (uint32_t)width;
				data.Height = (uint32_t)height;
				WindowResizeEvent e(data.Width, data.Height);
				data.EventCallback(e);
			});

		glfwSetWindowPosCallback(WindowObject, [](GLFWwindow* window, int xpos, int ypos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowMovedEvent e(xpos, ypos);
				data.EventCallback(e);
			});

		glfwSetWindowCloseCallback(WindowObject, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent e;
				data.EventCallback(e);
			});

		glfwSetKeyCallback(WindowObject, [](GLFWwindow* window, int key, int scanCode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent e((uint32_t)key, 0);
					data.EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent e((uint32_t)key);
					data.EventCallback(e);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent e((uint32_t)key, 1); //GLFW does not keep track of the repeat count
					data.EventCallback(e);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(WindowObject, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent e((uint32_t)button);
					data.EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e((uint32_t)button);
					data.EventCallback(e);
					break;
				}
				}
			});

		glfwSetScrollCallback(WindowObject, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent e(xOffset, yOffset);
				data.EventCallback(e);
			});

		glfwSetCursorPosCallback(WindowObject, [](GLFWwindow* window, double xPosition, double yPosition)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent e(xPosition, yPosition);
				data.EventCallback(e);
			});
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