#include "PyroEnginePCH.h"
#include "Vector3.h"
#include "PyroEngine/Maths/MathF.h"

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
		MathF::ResetVector3(&x);
	}

	void Vector3::Add(Vector3& v)
	{
		MathF::AddVector3(&x, &x, &v.x);
	}

	void Vector3::Sub(Vector3& v)
	{
		MathF::SubVector3(&x, &x, &v.x);
	}

	float Vector3::Dot(Vector3& v)
	{
		return MathF::DotVector3(&x, &v.x);
	}

	float Vector3::SqMagnitude()
	{
		return MathF::SqMagnitudeVector3(&x);
	}

	float Vector3::Magnitude()
	{
		return MathF::MagnitudeVector3(&x);
	}

	void Vector3::Normalise()
	{
		MathF::NormaliseVector3(&x, &x);
	}
}