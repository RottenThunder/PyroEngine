#pragma once
#include <vector>
#include "Core.h"
#include "Program.h"

namespace PyroEngine
{
	class Engine
	{
	private:
		static bool m_Running;
		static std::vector<Program*> m_Programs;
	public:
		static void Init();
		static void Terminate();

		static void AddProgram(Program* program);
		static void RemoveProgram(Program* program);
		static void Run();
		static void StopRunning();
	};
}