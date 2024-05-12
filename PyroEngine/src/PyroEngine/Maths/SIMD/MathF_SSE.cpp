#include "PyroEnginePCH.h"
#include "MathF_SSE.h"

namespace PyroEngine
{
	void MathF_SSE::ResetVector2(float* dst)
	{
		dst[0] = 0.0f;
		dst[1] = 0.0f;
	}

	void MathF_SSE::ResetVector3(float* dst)
	{
		dst[0] = 0.0f;
		dst[1] = 0.0f;
		dst[2] = 0.0f;
	}

	void MathF_SSE::ResetVector4(float* dst)
	{
		_mm_storeu_ps(dst, _mm_setzero_ps());
	}

	void MathF_SSE::AddVector2(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
	}

	void MathF_SSE::AddVector3(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
	}

	void MathF_SSE::AddVector4(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::SubVector2(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
	}

	void MathF_SSE::SubVector3(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
	}

	void MathF_SSE::SubVector4(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}
}