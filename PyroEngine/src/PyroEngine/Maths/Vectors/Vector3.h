#pragma once

namespace PyroEngine
{
	class Vector3
	{
	public:
		float x, y, z;

		Vector3();
		Vector3(float ix, float iy, float iz);

		void Reset();

		float SqMagnitude();
		float Magnitude();

		void Normalise();
	};
}