#pragma once
#include "PyroEnginePCH.h"
#include "Base.h"
#include "PyroEngine/Events/Event.h"

namespace PyroEngine
{
	class Window
	{
	public:
		virtual ~Window() {}

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const std::function<void(Event&)>& callback) = 0;
		virtual void SetVSync(bool vSync) = 0;
		virtual bool IsVSync() const = 0;

		virtual void OnUpdate() = 0;

		static Window* Create(const std::string& title, uint32_t width, uint32_t height);
	};
}