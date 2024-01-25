#include "PyroEnginePCH.h"
#include "Application.h"

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
		std::cout << "Welcome To PyroEngine!" << std::endl;
		std::cin.get();
	}
}