#include "PyroEnginePCH.h"
#include "Engine.h"
#include "ProcessorAnalyser.h"
#include "PyroEngine/Maths/MathF.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PyroEngine
{
	bool Engine::m_Running = true;
	std::vector<Application*> Engine::m_Applications;
	GlobalSettings Engine::m_Settings;

	void Engine::Init()
	{
		int init = glfwInit();
		PYRO_ASSERT(init == GLFW_TRUE, "GLFW did not initialise");

		ProcessorAnalyser::Analyse();
		std::cout << "CPU Name: " << ProcessorAnalyser::s_ProcessorName << std::endl;
		std::cout << "CPU Is Intel: " << ProcessorAnalyser::s_IsIntel << std::endl;
		std::cout << "CPU Is AMD: " << ProcessorAnalyser::s_IsAMD << std::endl;
		std::cout << "CPU MMX Functionality: " << ProcessorAnalyser::s_MMX << std::endl;
		std::cout << "CPU SSE 1.0 Functionality: " << ProcessorAnalyser::s_SSE << std::endl;
		std::cout << "CPU SSE 2.0 Functionality: " << ProcessorAnalyser::s_SSE2 << std::endl;
		std::cout << "CPU SSE 3.0 Functionality: " << ProcessorAnalyser::s_SSE3 << std::endl;
		std::cout << "CPU SSSE 3.0 Functionality: " << ProcessorAnalyser::s_SSSE3 << std::endl;
		std::cout << "CPU SSE 4.1 Functionality: " << ProcessorAnalyser::s_SSE41 << std::endl;
		std::cout << "CPU SSE 4.2 Functionality: " << ProcessorAnalyser::s_SSE42 << std::endl;
		std::cout << "CPU AVX 1.0 Functionality: " << ProcessorAnalyser::s_AVX << std::endl;
		std::cout << "CPU AVX 2.0 Functionality: " << ProcessorAnalyser::s_AVX2 << std::endl;
		std::cout << "CPU FMA Functionality: " << ProcessorAnalyser::s_FMA << std::endl;
		std::cout << "CPU AVX512 Functionality: " << ProcessorAnalyser::s_AVX512F << std::endl;
		std::cout << "CPU AVX512 PF Functionality: " << ProcessorAnalyser::s_AVX512PF << std::endl;
		std::cout << "CPU AVX512 ER Functionality: " << ProcessorAnalyser::s_AVX512ER << std::endl;
		std::cout << "CPU AVX512 CD Functionality: " << ProcessorAnalyser::s_AVX512CD << std::endl;

		MathF::Init();
	}

	void Engine::Terminate()
	{
		for (Application* app : m_Applications)
			app->OnDetach();

		m_Applications.clear();

		glfwTerminate();
	}

	void Engine::AddApplication(Application* app)
	{
		m_Applications.push_back(app);
		app->OnAttach();
	}

	void Engine::RemoveApplication(Application* app)
	{
		auto it = std::find(m_Applications.begin(), m_Applications.end(), app);
		if (it != m_Applications.end())
		{
			app->OnDetach();
			m_Applications.erase(it);
		}
	}

	void Engine::Run()
	{
		while (m_Running)
		{
			for (Application* app : m_Applications)
			{
				app->OnUpdate();
			}
		}
	}

	void Engine::StopRunning()
	{
		m_Running = false;
	}

	GlobalSettings& Engine::GetGlobalSettings()
	{
		return m_Settings;
	}
}