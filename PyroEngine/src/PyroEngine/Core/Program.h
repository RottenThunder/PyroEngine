#pragma once
#include "Core.h"
#include "Window.h"
#include "PyroEngine/Renderer/OpenGL/OpenGLVertexArray.h"
#include "PyroEngine/Renderer/OpenGL/OpenGLShader.h"
#include "PyroEngine/Renderer/OpenGL/OpenGLTexture.h"

namespace PyroEngine
{
	class Program
	{
	protected:
		Window p_Window;
	public:
		Program(const std::string& name = "PyroEngine", int width = 1280, int height = 720) : p_Window(name, width, height) {}
		virtual ~Program() {}

		void OnEngineAttach();
		void OnEngineDetach();
		void OnEngineUpdate();
		void OnEngineEvent(Event& e);

		virtual void OnProgramAttach();
		virtual void OnProgramDetach();
		virtual void OnProgramUpdate();
		virtual void OnProgramEvent(Event& e);
	};
}

#include "Engine.h"