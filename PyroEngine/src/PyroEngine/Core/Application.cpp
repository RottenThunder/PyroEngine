#include "PyroEnginePCH.h"
#include "Application.h"
#include <GLFW/glfw3.h> //For the clear colour

namespace PyroEngine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create("Pyro Engine", 1280, 720));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1.0f, 0.25f, 0.125f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
	}

	//TODO: Put into OnEvent Function
	//for (auto it = layerStack.end(); it != layerStack.begin();)
	//{
	//	(*--it)->OnEvent(e);
	//	if (e.handled)
	//		break;
	//}
}