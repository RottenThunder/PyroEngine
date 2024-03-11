#include "PyroEnginePCH.h"
#include "Window.h"
#include "Core.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PyroEngine
{
	Window::Window(const std::string& name, int width, int height)
	{
		m_Window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
		PYRO_ASSERT(m_Window, "Window Creation was unsuccessful");

		glfwMakeContextCurrent(m_Window);

		int gladInit = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PYRO_ASSERT(gladInit == GLFW_TRUE, "Glad did not initialise");

		glfwSetWindowUserPointer(m_Window, &m_Properties);
		glfwGetWindowPos(m_Window, &m_Properties.m_PosX, &m_Properties.m_PosY);

		m_Properties.m_Name = name;
		m_Properties.m_Width = width;
		m_Properties.m_Height = height;

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

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
}