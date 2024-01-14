#include <PyroEngine.h>

int main()
{
	PyroEngine::Application* app = new PyroEngine::Application();
	app->Run();
	delete app;
}