#include "PyroEnginePCH.h"
#include "MathF.h"
#include "SIMD/MathF_NULL.h"

namespace PyroEngine
{
	void (*MathF::ResetVector2)(float*) = nullptr;
	void (*MathF::ResetVector3)(float*) = nullptr;
	void (*MathF::ResetVector4)(float*) = nullptr;

	void (*MathF::AddVector2)(float*, float*, float*) = nullptr;
	void (*MathF::AddVector3)(float*, float*, float*) = nullptr;
	void (*MathF::AddVector4)(float*, float*, float*) = nullptr;

	void (*MathF::SubVector2)(float*, float*, float*) = nullptr;
	void (*MathF::SubVector3)(float*, float*, float*) = nullptr;
	void (*MathF::SubVector4)(float*, float*, float*) = nullptr;

	void MathF::Init()
	{
		MathF::ResetVector2 = MathF_NULL::ResetVector2;
		MathF::ResetVector3 = MathF_NULL::ResetVector3;
		MathF::ResetVector4 = MathF_NULL::ResetVector4;

		MathF::AddVector2 = MathF_NULL::AddVector2;
		MathF::AddVector3 = MathF_NULL::AddVector3;
		MathF::AddVector4 = MathF_NULL::AddVector4;

		MathF::SubVector2 = MathF_NULL::SubVector2;
		MathF::SubVector3 = MathF_NULL::SubVector3;
		MathF::SubVector4 = MathF_NULL::SubVector4;
	}
}