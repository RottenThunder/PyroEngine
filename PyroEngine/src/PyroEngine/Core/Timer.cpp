#include "PyroEnginePCH.h"
#include "Timer.h"

namespace PyroEngine
{
	Timer::Timer()
	{
		m_Time = std::chrono::steady_clock::now();
	}

	void Timer::Reset()
	{
		m_Time = std::chrono::steady_clock::now();
	}

	float Timer::GetSeconds()
	{
		std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
		std::chrono::duration<float> diff = currentTime - m_Time;
		return diff.count();
	}
}