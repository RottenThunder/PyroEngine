#pragma once
#include "PyroEngine/Core/Window.h"
#include <GLFW/glfw3.h>

namespace PyroEngine
{
	class WindowsWindow : public Window
	{
	private:
		struct WindowData
		{
			std::string Title;
			uint32_t Width;
			uint32_t Height;
			int32_t PosX;
			int32_t PosY;
			std::function<void(Event&)> EventCallback;
			bool VSync;
		};

		GLFWwindow* WindowObject;
		WindowData windowData;

		virtual void Init(const std::string& title, uint32_t width, uint32_t height);
		virtual void Terminate();
	public:
		WindowsWindow(const std::string& title, uint32_t width, uint32_t height);
		virtual ~WindowsWindow();

		virtual inline void* GetNativeWindow() const override { return WindowObject; }

		virtual inline uint32_t GetWidth() const override { return windowData.Width; }
		virtual inline uint32_t GetHeight() const override { return windowData.Height; }

		virtual inline void SetEventCallback(const std::function<void(Event&)>& callback) override { windowData.EventCallback = callback; }
		virtual void SetVSync(bool vSync) override;
		virtual bool IsVSync() const override;

		virtual void OnUpdate() override;
	};
}