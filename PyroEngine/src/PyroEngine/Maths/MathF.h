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

		static float (*DotVector2)(float*, float*);
		static float (*DotVector3)(float*, float*);
		static float (*DotVector4)(float*, float*);

		static float (*SqMagnitudeVector2)(float*);
		static float (*SqMagnitudeVector3)(float*);
		static float (*SqMagnitudeVector4)(float*);

		static float (*MagnitudeVector2)(float*);
		static float (*MagnitudeVector3)(float*);
		static float (*MagnitudeVector4)(float*);

		static void (*NormaliseVector2)(float*, float*);
		static void (*NormaliseVector3)(float*, float*);
		static void (*NormaliseVector4)(float*, float*);
	};
}