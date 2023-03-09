#include "PyroEnginePCH.h"
#include "WindowsInput.h"
#include "PyroEngine/Core/Application.h"
#include <GLFW/glfw3.h>

namespace PyroEngine
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(uint32_t keyCode)
	{
		if (s_PyroToOpenGLKeyCodes.contains(keyCode))
		{
			auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
			auto state = glfwGetKey(window, s_PyroToOpenGLKeyCodes.at(keyCode));
			return state == GLFW_PRESS || state == GLFW_REPEAT;
		}

		return false;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(uint32_t mouseButton)
	{
		if (s_PyroToOpenGLMouseButtonCodes.contains(mouseButton))
		{
			auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
			auto state = glfwGetMouseButton(window, s_PyroToOpenGLMouseButtonCodes.at(mouseButton));
			return state == GLFW_PRESS;
		}

		return false;
	}

	double WindowsInput::GetMouseXImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos;
		glfwGetCursorPos(window, &xPos, NULL);
		return xPos;
	}

	double WindowsInput::GetMouseYImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double yPos;
		glfwGetCursorPos(window, NULL, &yPos);
		return yPos;
	}
}