#pragma once
#include "Base.h"
#include "LayerStack.h"
#include "Window.h"
#include "PyroEngine/Events/WindowEvent.h"

namespace PyroEngine
{
	class Application
	{
	private:
		static Application* s_Instance;

		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;

		bool OnWindowClose(WindowCloseEvent& e);
	public:
		Application();
		virtual ~Application();

		void Run();
		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void OnEvent(Event& e);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	};

	//Will be defined in client-side code
	//e.g The Sandbox project
	Application* CreateApplication();
}