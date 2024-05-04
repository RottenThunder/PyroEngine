#include "PyroEnginePCH.h"
#include "Vector4.h"

namespace PyroEngine
{
	Vector4::Vector4()
	{
		Reset();
	}

	Vector4::Vector4(float ix, float iy, float iz, float iw)
		: x(ix), y(iy), z(iz), w(iw)
	{
	}

	void Vector4::Reset()
	{
	}

	float Vector4::SqMagnitude()
	{
		return 0.0f;
	}

	float Vector4::Magnitude()
	{
		return 0.0f;
	}

	void Vector4::Normalise()
	{
	}
}