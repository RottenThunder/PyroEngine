#include <PyroEngine.h>

class MainApplication : public PyroEngine::Application
{
private:
	PyroEngine::Window window;
public:
	MainApplication()
		: Application(), window("PyroEngine", 1280, 720) {}

	virtual void OnAttach() override
	{
		window.SetEventCallback(PYRO_BIND_EVENT_FUNCTION(MainApplication::OnEvent));
	}

	virtual void OnDetach() override
	{
	}

	virtual void OnUpdate() override
	{
		window.OnUpdate();
	}

	virtual void OnEvent(PyroEngine::Event& e) override
	{
		std::cout << e.GetName() << std::endl;

		if (e.GetEventType() == PyroEngine::EventType::WindowClosed)
			PyroEngine::Engine::StopRunning();
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