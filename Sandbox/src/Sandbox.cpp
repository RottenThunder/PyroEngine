#include <PyroEngine.h>

class Sandbox : public PyroEngine::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

PyroEngine::Application* PyroEngine::CreateApplication()
{
	return new Sandbox();
}