#include <PyroEngine.h>

class MainApplication : public PyroEngine::WindowApplication
{
public:
	MainApplication()
		: WindowApplication() {}

	virtual void OnWindowAttach() override
	{
	}

	virtual void OnWindowDetach() override
	{
	}

	virtual void OnWindowUpdate() override
	{
	}

	virtual void OnWindowEvent(PyroEngine::Event& e) override
	{
		std::cout << e.GetName() << std::endl;
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