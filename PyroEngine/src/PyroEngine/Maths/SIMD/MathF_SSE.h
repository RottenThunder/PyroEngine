#pragma once

namespace PyroEngine
{
	struct MathF_SSE
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
	};
}