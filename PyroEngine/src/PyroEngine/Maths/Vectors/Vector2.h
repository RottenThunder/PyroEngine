#pragma once

namespace PyroEngine
{
	struct Vector2
	{
		float x, y;

		Vector2();
		Vector2(float ix, float iy);

		void Reset();

		void Add(Vector2& v);
		void Sub(Vector2& v);

		float Dot(Vector2& v);

		float SqMagnitude();
		float Magnitude();

		void Normalise();
	};
}