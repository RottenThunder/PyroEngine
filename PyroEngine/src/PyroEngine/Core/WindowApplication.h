#pragma once
#include "Application.h"
#include "Core.h"
#include "Engine.h"
#include "Window.h"

namespace PyroEngine
{
	class WindowApplication : public Application
	{
	protected:
		Window m_Window;
	public:
		WindowApplication(const std::string& name = "PyroEngine", int width = 1280, int height = 720) : Application(), m_Window(name, width, height) {}
		virtual ~WindowApplication() {}

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& e) override;

		virtual void OnWindowAttach();
		virtual void OnWindowDetach();
		virtual void OnWindowUpdate();
		virtual void OnWindowEvent(Event& e);
	};
}