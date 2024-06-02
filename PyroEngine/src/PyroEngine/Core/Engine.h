#pragma once
#include <vector>
#include "Core.h"
#include "Application.h"

namespace PyroEngine
{
	class Engine
	{
	private:
		static bool m_Running;
		static std::vector<Application*> m_Applications;
	public:
		static PYRO_TYPE_ERROR Init();
		static PYRO_TYPE_ERROR InitWithoutLogger();
		static void Terminate();

		static void AddApplication(Application* app);
		static void RemoveApplication(Application* app);
		static void Run();
		static void StopRunning();
	};
}