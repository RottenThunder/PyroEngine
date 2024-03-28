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
		if (m_Window.IsKeyPressed(PYRO_KEY_X))
			std::cout << "X Key Was Pressed!!!" << std::endl;
		if (m_Window.IsKeyPressed(PYRO_KEY_Y))
			std::cout << "Y Key Was Pressed!!!" << std::endl;
		if (m_Window.IsMouseButtonPressed(PYRO_MOUSE_BUTTON_LEFT))
			std::cout << "Left Mouse Button Was Pressed!!!" << std::endl;
		if (m_Window.IsMouseButtonPressed(PYRO_MOUSE_BUTTON_RIGHT))
			std::cout << "Right Mouse Button Was Pressed!!!" << std::endl;

		std::cout << "Mouse: " << m_Window.GetMouseX() << ", " << m_Window.GetMouseY() << std::endl;
	}

	virtual void OnWindowEvent(PyroEngine::Event& e) override
	{
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