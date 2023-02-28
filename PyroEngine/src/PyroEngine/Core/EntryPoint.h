#pragma once
#include "Init.h"
#include "Application.h"

extern PyroEngine::Application* PyroEngine::CreateApplication();

int main()
{
	PyroEngine::Init();
	auto app = PyroEngine::CreateApplication();
	app->Run();
	delete app;
	PyroEngine::Terminate();
}