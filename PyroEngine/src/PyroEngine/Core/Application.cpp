#include "PyroEnginePCH.h"
#include "Application.h"
#include "PyroEngine/Events/WindowEvent.h"
#include "PyroEngine/Events/KeyEvent.h"
#include "PyroEngine/Events/MouseEvent.h"

namespace PyroEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Welcome to Pyro Engine!" << std::endl;
		std::cout << "\n";

		WindowMovedEvent e0(1280, 720);
		std::cout << e0.GetX() << std::endl;
		std::cout << e0.GetY() << std::endl;
		std::cout << e0.IsInCategory(EventCategory::Window) << std::endl;
		std::cout << e0.GetName() << std::endl;
		std::cout << "\n";

		WindowResizeEvent e1(1280, 720);
		std::cout << e1.GetWidth() << std::endl;
		std::cout << e1.GetHeight() << std::endl;
		std::cout << e1.IsInCategory(EventCategory::Mouse) << std::endl;
		std::cout << e1.GetName() << std::endl;
		std::cout << "\n";

		KeyPressedEvent e2(10, 2);
		std::cout << e2.GetKeyCode() << std::endl;
		std::cout << e2.GetRepeatCount() << std::endl;
		std::cout << e2.IsInCategory(EventCategory::MouseButton) << std::endl;
		std::cout << e2.GetName() << std::endl;
		std::cout << "\n";

		KeyReleasedEvent e3(10);
		std::cout << e3.GetKeyCode() << std::endl;
		std::cout << e3.IsInCategory(EventCategory::Input) << std::endl;
		std::cout << e3.GetName() << std::endl;
		std::cout << "\n";

		MouseButtonPressedEvent e4(2);
		std::cout << e4.GetMouseButton() << std::endl;
		std::cout << e4.IsInCategory(EventCategory::Key) << std::endl;
		std::cout << e4.GetName() << std::endl;
		std::cout << "\n";

		MouseButtonReleasedEvent e5(2);
		std::cout << e5.GetMouseButton() << std::endl;
		std::cout << e5.IsInCategory(EventCategory::MouseButton) << std::endl;
		std::cout << e5.GetName() << std::endl;
		std::cout << "\n";

		MouseMovedEvent e6(480.0f, 379.0f);
		std::cout << e6.GetX() << std::endl;
		std::cout << e6.GetY() << std::endl;
		std::cout << e6.IsInCategory(EventCategory::Window) << std::endl;
		std::cout << e6.GetName() << std::endl;
		std::cout << "\n";

		MouseScrolledEvent e7(245.0f, 569.0f);
		std::cout << e7.GetXOffset() << std::endl;
		std::cout << e7.GetYOffset() << std::endl;
		std::cout << e7.IsInCategory(EventCategory::None) << std::endl;
		std::cout << e7.GetName() << std::endl;
		std::cout << "\n";

		WindowCloseEvent c;
		std::cout << c.IsInCategory(EventCategory::Input) << std::endl;
		std::cout << c.GetName() << std::endl;
	}
}