#pragma once

namespace PyroEngine
{
	struct MathF_NULL
	{
		static void ResetVector2(float* dst);
		static void ResetVector3(float* dst);
		static void ResetVector4(float* dst);

		static void AddVector2(float* dst, float* vec1, float* vec2);
		static void AddVector3(float* dst, float* vec1, float* vec2);
		static void AddVector4(float* dst, float* vec1, float* vec2);

		static void SubVector2(float* dst, float* vec1, float* vec2);
		static void SubVector3(float* dst, float* vec1, float* vec2);
		static void SubVector4(float* dst, float* vec1, float* vec2);

		static float DotVector2(float* vec1, float* vec2);
		static float DotVector3(float* vec1, float* vec2);
		static float DotVector4(float* vec1, float* vec2);

		static float SqMagnitudeVector2(float* vec1);
		static float SqMagnitudeVector3(float* vec1);
		static float SqMagnitudeVector4(float* vec1);

		static float MagnitudeVector2(float* vec1);
		static float MagnitudeVector3(float* vec1);
		static float MagnitudeVector4(float* vec1);

		static void NormaliseVector2(float* dst, float* vec1);
		static void NormaliseVector3(float* dst, float* vec1);
		static void NormaliseVector4(float* dst, float* vec1);
	};
}