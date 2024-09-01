#include <PyroEngine.h>

class MainProgram : public PyroEngine::Program
{
private:
	PyroEngine::Camera camera;
	float time;
public:
	MainProgram()
		: Program() {}

	virtual void OnProgramAttach() override
	{
		time = 0.0f;
		camera.Set({ 12.0f, 12.0f }, 0.0f, 1.0f, 0.0625f);
	}

	virtual void OnProgramDetach() override
	{
	}

	virtual void OnProgramUpdate(float deltaTime) override
	{
		time += deltaTime;
		PyroEngine::Renderer::ClearScreen({ std::abs(std::sin(time)) * 0.25f });
		PyroEngine::Renderer::BeginScene(camera);
		for (float y = 0.0f; y < 25.0f; y += 1.0f)
		{
			for (float x = 0.0f; x < 25.0f; x += 1.0f)
			{
				PyroEngine::Renderer::DrawQuad({ x, y }, 0.0f, { 0.75f, 0.75f }, { std::abs(std::sin(time + y)), std::abs(std::cos(time + x)), std::abs(std::sin(time + x + y)), std::abs(std::cos(time + x + y)) });
			}
		}
		PyroEngine::Renderer::EndScene();
	}

	virtual void OnProgramEvent(PyroEngine::Event& e) override
	{
		if (e.GetEventType() == PyroEngine::KeyPressed)
		{
			PyroEngine::KeyPressedEvent keyPressedEvent = (PyroEngine::KeyPressedEvent&)e;
			if (keyPressedEvent.GetKeyCode() == PYRO_KEY_W)
			{
				PyroEngine::Vector2 vec2 = camera.GetPosition();
				vec2.y += 0.125f;
				camera.SetPosition(vec2);
			}
			if (keyPressedEvent.GetKeyCode() == PYRO_KEY_S)
			{
				PyroEngine::Vector2 vec2 = camera.GetPosition();
				vec2.y -= 0.125f;
				camera.SetPosition(vec2);
			}
			if (keyPressedEvent.GetKeyCode() == PYRO_KEY_A)
			{
				PyroEngine::Vector2 vec2 = camera.GetPosition();
				vec2.x -= 0.125f;
				camera.SetPosition(vec2);
			}
			if (keyPressedEvent.GetKeyCode() == PYRO_KEY_D)
			{
				PyroEngine::Vector2 vec2 = camera.GetPosition();
				vec2.x += 0.125f;
				camera.SetPosition(vec2);
			}
		}
	}
};

int main(int argc, char** argv)
{
	PyroEngine::GlobalSettings::s_GraphicsAPI = PyroEngine::GraphicsAPI::OpenGL;
	PyroEngine::Engine::Init();
	MainProgram* mainProgram = new MainProgram();
	PyroEngine::Engine::AddProgram(mainProgram);
	PyroEngine::Engine::Run();
	PyroEngine::Engine::Terminate();
	delete mainProgram;
	return 0;
}

#if defined PYRO_PLATFORM_WINDOWS && PYRO_CONFIG_RELEASE

#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	int argc = 0;
	char** argv = nullptr;

	std::vector<size_t> argSizes;
	size_t currentArgSize = 0;
	size_t cmdLineSize = std::strlen(lpCmdLine);

	char* cmdLine = nullptr;

	if (cmdLineSize == 0)
	{
		const char* baseStr = "PyroEngine";
		cmdLine = (char*)::operator new((std::strlen(baseStr) + 1) * sizeof(char));
		std::strcpy(cmdLine, baseStr);
		cmdLineSize = std::strlen(cmdLine);
	}
	else
	{
		cmdLine = (char*)::operator new((cmdLineSize + 1) * sizeof(char));
		std::strcpy(cmdLine, lpCmdLine);
	}

	for (size_t i = 0; i < cmdLineSize; i++)
	{
		if (cmdLine[i] == ' ')
		{
			argc++;
			argSizes.push_back(currentArgSize);
			currentArgSize = 0;
		}
		else
			currentArgSize++;
	}
	argc++;
	argSizes.push_back(currentArgSize);

	argv = (char**)::operator new(argSizes.size() * sizeof(char*));
	for (size_t i = 0; i < argSizes.size(); i++)
		argv[i] = (char*)::operator new((argSizes[i] + 1) * sizeof(char));

	size_t currentCharIndex = 0;
	for (size_t i = 0; i < argSizes.size(); i++)
	{
		for (size_t j = 0; j < argSizes[i]; j++)
		{
			argv[i][j] = cmdLine[currentCharIndex];
			currentCharIndex++;
		}

		argv[i][argSizes[i]] = '\0';
		currentCharIndex++;
	}

	int exit_code = main(argc, argv);

	for (size_t i = 0; i < argSizes.size(); i++)
		::operator delete(argv[i], (argSizes[i] + 1) * sizeof(char));

	::operator delete(argv, argSizes.size() * sizeof(char*));

	::operator delete(cmdLine, (cmdLineSize + 1) * sizeof(char));

	return exit_code;
}

#endif