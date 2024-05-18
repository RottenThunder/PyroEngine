#pragma once

namespace PyroEngine
{
	struct Vector4
	{
		float x, y, z, w;

		Vector4();
		Vector4(float ix, float iy, float iz, float iw);

		void Reset();

		void Add(Vector4& v);
		void Sub(Vector4& v);

		float Dot(Vector4& v);

		float SqMagnitude();
		float Magnitude();

		void Normalise();
	};
}