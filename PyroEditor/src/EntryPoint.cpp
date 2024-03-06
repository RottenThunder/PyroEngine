#include <PyroEngine.h>

class MainApplication : public PyroEngine::Application
{
public:
	MainApplication()
		: Application() {}

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
	}
};

int main()
{
	PyroEngine::Engine* engine = new PyroEngine::Engine();
	MainApplication* mainApp = new MainApplication();
	engine->AddApplication(mainApp);
	engine->Run();
	delete engine;
	delete mainApp;
}