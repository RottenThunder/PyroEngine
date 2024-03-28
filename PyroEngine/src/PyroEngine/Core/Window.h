#pragma once
#include <functional>
#include "PyroEngine/Events/KeyEvent.h"
#include "PyroEngine/Events/MouseEvent.h"
#include "PyroEngine/Events/WindowEvent.h"

struct GLFWwindow;

namespace PyroEngine
{
	struct WindowProperties
	{
		std::string m_Name;
		int m_Width;
		int m_Height;
		int m_PosX;
		int m_PosY;
		bool m_VSync;
		std::function<void(Event&)> m_EventCallback;
	};

	class Window
	{
	private:
		GLFWwindow* m_Window;
		WindowProperties m_Properties;
	public:
		Window(const std::string& name, int width, int height);
		~Window();

		int GetWidth() const;
		int GetHeight() const;
		int GetPosX() const;
		int GetPosY() const;

		bool IsKeyPressed(int keyCode) const;
		bool IsMouseButtonPressed(int mouseButton) const;
		double GetMouseX() const;
		double GetMouseY() const;

		void SetVSync(bool vSync);
		bool IsVSync() const;

		void SetEventCallback(const std::function<void(Event&)>& callback);

		void OnUpdate() const;
	};
}