#pragma once

namespace PyroEngine
{
	class Vector4
	{
	public:
		float x, y, z, w;

		Vector4();
		Vector4(float ix, float iy, float iz, float iw);

		void Reset();

		float SqMagnitude();
		float Magnitude();

		void Normalise();
	};
}