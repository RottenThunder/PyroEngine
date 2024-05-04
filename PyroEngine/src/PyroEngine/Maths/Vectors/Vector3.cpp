#include "PyroEnginePCH.h"
#include "Vector3.h"

namespace PyroEngine
{
	Vector3::Vector3()
	{
		Reset();
	}

	Vector3::Vector3(float ix, float iy, float iz)
		: x(ix), y(iy), z(iz)
	{
	}

	void Vector3::Reset()
	{
	}

	float Vector3::SqMagnitude()
	{
		return 0.0f;
	}

	float Vector3::Magnitude()
	{
		return 0.0f;
	}

	void Vector3::Normalise()
	{
	}
}