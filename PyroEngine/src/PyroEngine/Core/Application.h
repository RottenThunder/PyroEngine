#pragma once
#include "Base.h"
#include "LayerStack.h"

namespace PyroEngine
{
	class Application
	{
	private:
		LayerStack m_LayerStack;
	public:
		Application();
		virtual ~Application();

		void Run();
		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
	};

	//Will be defined in client-side code
	//e.g The Sandbox project
	Application* CreateApplication();
}