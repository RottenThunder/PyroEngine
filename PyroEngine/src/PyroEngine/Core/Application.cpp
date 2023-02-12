#include "Application.h"
#include <iostream>

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
	}
}