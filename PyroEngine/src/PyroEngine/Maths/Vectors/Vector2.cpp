#include "PyroEnginePCH.h"
#include "Vector2.h"
#include "PyroEngine/Maths/MathF.h"

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
		MathF::ResetVector2(&x);
	}

	void Vector2::Add(Vector2& v)
	{
		MathF::AddVector2(&x, &x, &v.x);
	}

	void Vector2::Sub(Vector2& v)
	{
		MathF::SubVector2(&x, &x, &v.x);
	}

	float Vector2::Dot(Vector2& v)
	{
		return MathF::DotVector2(&x, &v.x);
	}

	float Vector2::SqMagnitude()
	{
		return MathF::SqMagnitudeVector2(&x);
	}

	float Vector2::Magnitude()
	{
		return MathF::MagnitudeVector2(&x);
	}

	void Vector2::Normalise()
	{
		MathF::NormaliseVector2(&x, &x);
	}
}