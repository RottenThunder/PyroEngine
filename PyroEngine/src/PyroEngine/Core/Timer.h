#pragma once

namespace PyroEngine
{
	class Timer
	{
	private:
		std::chrono::steady_clock::time_point m_Time;
	public:
		Timer();

		void Reset();
		float GetSeconds();
	};
}