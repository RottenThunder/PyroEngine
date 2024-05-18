#include "PyroEnginePCH.h"
#include "Vector4.h"
#include "PyroEngine/Maths/MathF.h"

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
		MathF::ResetVector4(&x);
	}

	void Vector4::Add(Vector4& v)
	{
		MathF::AddVector4(&x, &x, &v.x);
	}

	void Vector4::Sub(Vector4& v)
	{
		MathF::SubVector4(&x, &x, &v.x);
	}

	float Vector4::Dot(Vector4& v)
	{
		return MathF::DotVector4(&x, &v.x);
	}

	float Vector4::SqMagnitude()
	{
		return MathF::SqMagnitudeVector4(&x);
	}

	float Vector4::Magnitude()
	{
		return MathF::MagnitudeVector4(&x);
	}

	void Vector4::Normalise()
	{
		MathF::NormaliseVector4(&x, &x);
	}
}