#include <PyroEngine.h>

class ExampleLayer : public PyroEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		if (PyroEngine::Input::IsKeyPressed(PYRO_KEY_A))
			std::cout << "A Key Was Pressed!" << std::endl;
	}

	void OnEvent(PyroEngine::Event& e) override
	{
		if (e.GetEventType() == PyroEngine::EventType::KeyPressed)
		{
			PyroEngine::KeyPressedEvent& keyEvent = (PyroEngine::KeyPressedEvent&)e;
			std::cout << keyEvent.GetKeyCode() << std::endl;
		}
	}
};

class Sandbox : public PyroEngine::Application
{
private:
	ExampleLayer* m_ExampleLayer = nullptr;
public:
	Sandbox()
		: m_ExampleLayer(new ExampleLayer())
	{
		PushLayer(m_ExampleLayer);
	}

	~Sandbox()
	{
		PopLayer(m_ExampleLayer);
	}
};

PyroEngine::Application* PyroEngine::CreateApplication()
{
	return new Sandbox();
}