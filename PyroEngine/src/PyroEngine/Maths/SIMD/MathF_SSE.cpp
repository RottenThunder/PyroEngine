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

	float MathF_SSE::DotVector2(float* vec1, float* vec2)
	{
		float xSq = vec1[0] * vec2[0];
		float ySq = vec1[1] * vec2[1];
		return xSq + ySq;
	}

	float MathF_SSE::DotVector3(float* vec1, float* vec2)
	{
		float xSq = vec1[0] * vec2[0];
		float ySq = vec1[1] * vec2[1];
		float zSq = vec1[2] * vec2[2];
		return xSq + ySq + zSq;
	}

	float MathF_SSE::DotVector4(float* vec1, float* vec2)
	{
		__m128 vecSq = _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2));
		return vecSq.m128_f32[0] + vecSq.m128_f32[1] + vecSq.m128_f32[2] + vecSq.m128_f32[3];
	}

	float MathF_SSE::SqMagnitudeVector2(float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		return xSq + ySq;
	}

	float MathF_SSE::SqMagnitudeVector3(float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float zSq = vec1[2] * vec1[2];
		return xSq + ySq + zSq;
	}

	float MathF_SSE::SqMagnitudeVector4(float* vec1)
	{
		__m128 vecSq = _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec1));
		return vecSq.m128_f32[0] + vecSq.m128_f32[1] + vecSq.m128_f32[2] + vecSq.m128_f32[3];
	}

	float MathF_SSE::MagnitudeVector2(float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		return std::sqrt(xSq + ySq);
	}

	float MathF_SSE::MagnitudeVector3(float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float zSq = vec1[2] * vec1[2];
		return std::sqrt(xSq + ySq + zSq);
	}

	float MathF_SSE::MagnitudeVector4(float* vec1)
	{
		__m128 vecSq = _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec1));
		vecSq.m128_f32[0] += vecSq.m128_f32[1] + vecSq.m128_f32[2] + vecSq.m128_f32[3];
		return _mm_sqrt_ps(vecSq).m128_f32[0];
	}

	void MathF_SSE::NormaliseVector2(float* dst, float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float mag = std::sqrt(xSq + ySq);
		dst[0] = vec1[0] / mag;
		dst[1] = vec1[1] / mag;
	}

	void MathF_SSE::NormaliseVector3(float* dst, float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float zSq = vec1[2] * vec1[2];
		float mag = std::sqrt(xSq + ySq + zSq);
		dst[0] = vec1[0] / mag;
		dst[1] = vec1[1] / mag;
		dst[2] = vec1[2] / mag;
	}

	void MathF_SSE::NormaliseVector4(float* dst, float* vec1)
	{
		__m128 vecSq = _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec1));
		vecSq.m128_f32[0] += vecSq.m128_f32[1] + vecSq.m128_f32[2] + vecSq.m128_f32[3];
		vecSq = _mm_sqrt_ps(vecSq);
		vecSq.m128_f32[1] = vecSq.m128_f32[0];
		vecSq.m128_f32[2] = vecSq.m128_f32[0];
		vecSq.m128_f32[3] = vecSq.m128_f32[0];
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), vecSq));
	}
}