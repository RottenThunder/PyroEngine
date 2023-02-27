#include <PyroEngine.h>

class ExampleLayer : public PyroEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		std::cout << "ExampleLayer is Updating" << std::endl;
	}

	/*
	void OnEvent(PyroEngine::Event& e) override
	{
		std::cout << e.GetName() << std::endl;
	}
	*/
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