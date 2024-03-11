#pragma once
#include <string>

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

		void SetVSync(bool vSync);
		bool IsVSync() const;

		void OnUpdate();
	};
}