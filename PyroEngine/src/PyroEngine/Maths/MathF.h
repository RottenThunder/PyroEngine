#pragma once

namespace PyroEngine
{
	struct MathF
	{
		static void Init();

		static void (*ResetVector2)(float*);
		static void (*ResetVector3)(float*);
		static void (*ResetVector4)(float*);

		static void (*AddVector2)(float*, float*, float*);
		static void (*AddVector3)(float*, float*, float*);
		static void (*AddVector4)(float*, float*, float*);

		static void (*SubVector2)(float*, float*, float*);
		static void (*SubVector3)(float*, float*, float*);
		static void (*SubVector4)(float*, float*, float*);
	};
}