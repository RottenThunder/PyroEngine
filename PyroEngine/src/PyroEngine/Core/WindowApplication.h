#pragma once
#include "Application.h"
#include "Core.h"
#include "Engine.h"
#include "Window.h"
#include "PyroEngine/Renderer/OpenGL/OpenGLVertexArray.h"
#include "PyroEngine/Renderer/OpenGL/OpenGLShader.h"

namespace PyroEngine
{
	class WindowApplication : public Application
	{
	protected:
		Window m_Window;
		VertexArray* p_VertexArray = nullptr;
		Shader* p_Shader = nullptr;
	public:
		WindowApplication(const std::string& name = "PyroEngine", int width = 1280, int height = 720) : Application(), m_Window(name, width, height) {}
		virtual ~WindowApplication() {}

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& e) override;

		virtual void OnWindowAttach();
		virtual void OnWindowDetach();
		virtual void OnWindowUpdate();
		virtual void OnWindowEvent(Event& e);
	};
}