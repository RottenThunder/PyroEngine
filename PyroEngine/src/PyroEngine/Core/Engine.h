#pragma once
#include <vector>
#include "Core.h"
#include "Application.h"

namespace PyroEngine
{
	class Engine
	{
	private:
		bool m_Running = true;
		std::vector<Application*> m_Applications;
	public:
		Engine();
		~Engine();

		void AddApplication(Application* app);
		void RemoveApplication(Application* app);
		void Run();
	};
}