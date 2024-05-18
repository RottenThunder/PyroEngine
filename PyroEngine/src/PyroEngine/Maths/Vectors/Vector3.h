#pragma once

namespace PyroEngine
{
	struct Vector3
	{
		float x, y, z;

		Vector3();
		Vector3(float ix, float iy, float iz);

		void Reset();

		void Add(Vector3& v);
		void Sub(Vector3& v);

		float Dot(Vector3& v);

		float SqMagnitude();
		float Magnitude();

		void Normalise();
	};
}