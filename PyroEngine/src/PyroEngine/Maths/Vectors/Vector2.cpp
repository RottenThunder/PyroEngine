#include "PyroEnginePCH.h"
#include "Vector2.h"

namespace PyroEngine
{
	Vector2::Vector2()
	{
		Reset();
	}

	Vector2::Vector2(float ix, float iy)
		: x(ix), y(iy)
	{
	}

	void Vector2::Reset()
	{
	}

	float Vector2::SqMagnitude()
	{
		return 0.0f;
	}

	float Vector2::Magnitude()
	{
		return 0.0f;
	}

	void Vector2::Normalise()
	{
	}
}