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
		SIMDRegister128 zero(true);
		zero.Store(dst);
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
		SIMDRegister128 vecReg1(vec1);
		SIMDRegister128 vecReg2(vec2);
		vecReg1 += vecReg2;
		vecReg1.Store(dst);
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
		SIMDRegister128 vecReg1(vec1);
		SIMDRegister128 vecReg2(vec2);
		vecReg1 -= vecReg2;
		vecReg1.Store(dst);
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
		SIMDRegister128 vecReg1(vec1);
		SIMDRegister128 vecReg2(vec2);
		vecReg1 *= vecReg2;
		return vecReg1[0] + vecReg1[1] + vecReg1[2] + vecReg1[3];
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
		SIMDRegister128 vecReg(vec1);
		vecReg *= vecReg;
		return vecReg[0] + vecReg[1] + vecReg[2] + vecReg[3];
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
		SIMDRegister128 vecReg(vec1);
		vecReg *= vecReg;
		vecReg[0] += vecReg[1] + vecReg[2] + vecReg[3];
		vecReg.Sqrt();
		return vecReg[0];
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
		SIMDRegister128 vecReg(vec1);
		SIMDRegister128 vecRegClone(vec1);
		vecReg *= vecReg;
		vecReg[0] += vecReg[1] + vecReg[2] + vecReg[3];
		vecReg.Sqrt();
		vecReg[1] = vecReg[0];
		vecReg[2] = vecReg[0];
		vecReg[3] = vecReg[0];
		vecRegClone /= vecReg;
		vecRegClone.Store(dst);
	}
}