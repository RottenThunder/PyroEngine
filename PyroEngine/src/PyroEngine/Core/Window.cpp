#include "PyroEnginePCH.h"
#include "Window.h"
#include "Core.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PyroEngine
{
	Window::Window(const std::string& name, int width, int height)
	{
		m_Properties.m_Name = name;
		m_Properties.m_Width = width;
		m_Properties.m_Height = height;

		m_Window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
		PYRO_ASSERT(m_Window, "Window Creation was unsuccessful");

		glfwMakeContextCurrent(m_Window);

		int gladInit = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PYRO_ASSERT(gladInit == GLFW_TRUE, "Glad did not initialise");

		glfwSetWindowUserPointer(m_Window, &m_Properties);
		glfwGetWindowPos(m_Window, &m_Properties.m_PosX, &m_Properties.m_PosY);

		glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xPosition, int yPosition)
			{
				WindowProperties& props = *(WindowProperties*)glfwGetWindowUserPointer(window);
				props.m_PosX = xPosition;
				props.m_PosY = yPosition;
				WindowMovedEvent e(props.m_PosX, props.m_PosY);
				props.m_EventCallback(e);
			});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowProperties& props = *(WindowProperties*)glfwGetWindowUserPointer(window);
				props.m_Width = width;
				props.m_Height = height;
				WindowResizedEvent e(props.m_Width, props.m_Height);
				props.m_EventCallback(e);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowProperties& props = *(WindowProperties*)glfwGetWindowUserPointer(window);
				WindowClosedEvent e;
				props.m_EventCallback(e);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scanCode, int action, int mods)
			{
				WindowProperties& props = *(WindowProperties*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent e(key);
					props.m_EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent e(key);
					props.m_EventCallback(e);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent e(key);
					props.m_EventCallback(e);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowProperties& props = *(WindowProperties*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent e(button);
					props.m_EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e(button);
					props.m_EventCallback(e);
					break;
				}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowProperties& props = *(WindowProperties*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent e(xOffset, yOffset);
				props.m_EventCallback(e);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPosition, double yPosition)
			{
				WindowProperties& props = *(WindowProperties*)glfwGetWindowUserPointer(window);
				MouseMovedEvent e(xPosition, yPosition);
				props.m_EventCallback(e);
			});

		SetVSync(false);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
	}

	int Window::GetWidth() const
	{
		return m_Properties.m_Width;
	}

	int Window::GetHeight() const
	{
		return m_Properties.m_Height;
	}

	int Window::GetPosX() const
	{
		return m_Properties.m_PosX;
	}

	int Window::GetPosY() const
	{
		return m_Properties.m_PosY;
	}

	bool Window::IsKeyPressed(int keyCode) const
	{
		return glfwGetKey(m_Window, keyCode) == GLFW_PRESS;
	}

	bool Window::IsMouseButtonPressed(int mouseButton) const
	{
		return glfwGetMouseButton(m_Window, mouseButton) == GLFW_PRESS;
	}

	double Window::GetMouseX() const
	{
		double xPos;
		glfwGetCursorPos(m_Window, &xPos, NULL);
		return xPos;
	}

	double Window::GetMouseY() const
	{
		double yPos;
		glfwGetCursorPos(m_Window, NULL, &yPos);
		return yPos;
	}

	void Window::SetVSync(bool vSync)
	{
		if (vSync)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Properties.m_VSync = vSync;
	}

	bool Window::IsVSync() const
	{
		return m_Properties.m_VSync;
	}

	void Window::SetEventCallback(const std::function<void(Event&)>& callback)
	{
		m_Properties.m_EventCallback = callback;
	}

	void Window::OnUpdate() const
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
}