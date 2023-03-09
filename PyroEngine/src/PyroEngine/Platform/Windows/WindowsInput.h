#pragma once
#include "PyroEngine/Core/Input.h"

namespace PyroEngine
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(uint32_t keyCode) override;
		virtual bool IsMouseButtonPressedImpl(uint32_t mouseButton) override;
		virtual double GetMouseXImpl() override;
		virtual double GetMouseYImpl() override;
	};
}