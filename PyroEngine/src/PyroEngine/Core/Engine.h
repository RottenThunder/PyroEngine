#pragma once
#include <vector>
#include "Core.h"
#include "Application.h"
#include "GlobalSettings.h"

namespace PyroEngine
{
	class Engine
	{
	private:
		static bool m_Running;
		static std::vector<Application*> m_Applications;
		static GlobalSettings m_Settings;
	public:
		static void Init();
		static void Terminate();

		static void AddApplication(Application* app);
		static void RemoveApplication(Application* app);
		static void Run();
		static void StopRunning();
	};
}