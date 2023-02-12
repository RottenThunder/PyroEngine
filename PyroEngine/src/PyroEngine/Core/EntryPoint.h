#pragma once
#include "Application.h"

extern PyroEngine::Application* PyroEngine::CreateApplication();

int main()
{
	auto app = PyroEngine::CreateApplication();
	app->Run();
	delete app;
}