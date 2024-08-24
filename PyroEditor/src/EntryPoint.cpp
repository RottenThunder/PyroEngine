#include <PyroEngine.h>

class MainProgram : public PyroEngine::Program
{
private:
	PyroEngine::Camera camera;
	PyroEngine::Texture* tex1;
	PyroEngine::Texture* tex2;
public:
	MainProgram()
		: Program() {}

	virtual void OnProgramAttach() override
	{
		camera.Set({ 0.0f, 0.0f }, 0.0f, 1.0f, 1.0f);
		tex1 = PyroEngine::Texture::Create(5, 5);
		tex2 = PyroEngine::Texture::Create(3, 3);
		uint8_t tex1Colours[5 * 5 * 4];
		for (size_t i = 0; i < 5 * 5; i++)
		{
			tex1Colours[(i * 4) + 0] = (uint8_t)i * 10;
			tex1Colours[(i * 4) + 1] = (uint8_t)i * 5;
			tex1Colours[(i * 4) + 2] = (uint8_t)i * 8;
			tex1Colours[(i * 4) + 3] = 0xFF;
		}
		uint8_t tex2Colours[3 * 3 * 4];
		for (size_t i = 0; i < 3 * 3; i++)
		{
			tex2Colours[(i * 4) + 0] = (uint8_t)i * 3;
			tex2Colours[(i * 4) + 1] = (uint8_t)i * 10;
			tex2Colours[(i * 4) + 2] = (uint8_t)i * 7;
			tex2Colours[(i * 4) + 3] = 0xFF;
		}
		tex1->SetData(tex1Colours, 5 * 5 * 4);
		tex2->SetData(tex2Colours, 3 * 3 * 4);
	}

	virtual void OnProgramDetach() override
	{
	}

	virtual void OnProgramUpdate() override
	{
		PyroEngine::Renderer::BeginScene(camera);
		PyroEngine::Renderer::DrawQuad({ 0.5f, 0.5f }, 0.0f, { 0.25f, 0.25f }, 1.0f, 1.0f, 1.0f, tex1);
		PyroEngine::Renderer::DrawQuad({ -0.5f, -0.5f }, 0.0f, { 0.25f, 0.25f }, 1.0f, 1.0f, 1.0f, tex2);
		PyroEngine::Renderer::EndScene();
	}

	virtual void OnProgramEvent(PyroEngine::Event& e) override
	{
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