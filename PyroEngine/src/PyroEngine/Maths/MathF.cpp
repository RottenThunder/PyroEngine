#include "PyroEnginePCH.h"
#include "MathF.h"
#include "SIMD/MathF_NULL.h"
#include "SIMD/MathF_SSE.h"

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

	float (*MathF::DotVector2)(float*, float*) = nullptr;
	float (*MathF::DotVector3)(float*, float*) = nullptr;
	float (*MathF::DotVector4)(float*, float*) = nullptr;

	float (*MathF::SqMagnitudeVector2)(float*) = nullptr;
	float (*MathF::SqMagnitudeVector3)(float*) = nullptr;
	float (*MathF::SqMagnitudeVector4)(float*) = nullptr;

	float (*MathF::MagnitudeVector2)(float*) = nullptr;
	float (*MathF::MagnitudeVector3)(float*) = nullptr;
	float (*MathF::MagnitudeVector4)(float*) = nullptr;

	void (*MathF::NormaliseVector2)(float*, float*) = nullptr;
	void (*MathF::NormaliseVector3)(float*, float*) = nullptr;
	void (*MathF::NormaliseVector4)(float*, float*) = nullptr;

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

		MathF::DotVector2 = MathF_NULL::DotVector2;
		MathF::DotVector3 = MathF_NULL::DotVector3;
		MathF::DotVector4 = MathF_NULL::DotVector4;

		MathF::SqMagnitudeVector2 = MathF_NULL::SqMagnitudeVector2;
		MathF::SqMagnitudeVector3 = MathF_NULL::SqMagnitudeVector3;
		MathF::SqMagnitudeVector4 = MathF_NULL::SqMagnitudeVector4;

		MathF::MagnitudeVector2 = MathF_NULL::MagnitudeVector2;
		MathF::MagnitudeVector3 = MathF_NULL::MagnitudeVector3;
		MathF::MagnitudeVector4 = MathF_NULL::MagnitudeVector4;

		MathF::NormaliseVector2 = MathF_NULL::NormaliseVector2;
		MathF::NormaliseVector3 = MathF_NULL::NormaliseVector3;
		MathF::NormaliseVector4 = MathF_NULL::NormaliseVector4;
	}
}