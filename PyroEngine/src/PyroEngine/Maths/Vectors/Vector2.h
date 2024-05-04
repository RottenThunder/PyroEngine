#pragma once
#include "PyroEngine/Maths/MathF.h"

namespace PyroEngine
{
	class Vector2
	{
	public:
		float x, y;

		Vector2();
		Vector2(float ix, float iy);

		void Reset();

		float SqMagnitude();
		float Magnitude();

		void Normalise();
	};
}