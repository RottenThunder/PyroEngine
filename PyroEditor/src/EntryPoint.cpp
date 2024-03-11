#include <PyroEngine.h>

class MainApplication : public PyroEngine::Application
{
private:
	PyroEngine::Window window;
public:
	MainApplication()
		: Application(), window("PyroEngine", 1280, 720) {}

	void OnAttach() override
	{
		std::cout << "MainApplication Got Attached!" << std::endl;
	}

	void OnDetach() override
	{
		std::cout << "MainApplication Got Detached!" << std::endl;
	}

	void OnUpdate() override
	{
		std::cout << "MainApplication Is Updating!" << std::endl;
		window.OnUpdate();
	}
};

int main()
{
	PyroEngine::Engine::Init();
	MainApplication* mainApp = new MainApplication();
	PyroEngine::Engine::AddApplication(mainApp);
	PyroEngine::Engine::Run();
	PyroEngine::Engine::Terminate();
	delete mainApp;
}