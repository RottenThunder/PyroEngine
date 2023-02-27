#include "PyroEnginePCH.h"
#include "Application.h"
#include "PyroEngine/Events/WindowEvent.h"
#include "PyroEngine/Events/KeyEvent.h"
#include "PyroEngine/Events/MouseEvent.h"

namespace PyroEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Welcome to Pyro Engine!" << std::endl;
		std::cout << "\n";

		//TODO: Put into Run Loop
		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();
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