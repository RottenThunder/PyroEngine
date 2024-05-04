#pragma once

namespace PyroEngine
{
	struct MathF
	{
		static void Init();

		static void (*ResetVector2)(float*);
		static void (*ResetVector3)(float*);
		static void (*ResetVector4)(float*);
	};
}