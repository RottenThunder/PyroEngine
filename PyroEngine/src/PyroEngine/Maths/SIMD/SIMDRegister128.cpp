#include "PyroEnginePCH.h"
#include "SIMDRegister128.h"
#include "PyroEngine/Core/Core.h"

namespace PyroEngine
{
	SIMDRegister128::SIMDRegister128(bool setzero)
	{
		if (setzero)
			SetZero();
	}

	SIMDRegister128::SIMDRegister128(float* values)
	{
		Load(values);
	}

	SIMDRegister128::SIMDRegister128(__m128 base)
	{
		m_Register = base;
	}

	SIMDRegister128::~SIMDRegister128()
	{
	}

	__m128 SIMDRegister128::GetRegisterBaseType() const
	{
		return m_Register;
	}

	void SIMDRegister128::Load(float* values)
	{
		m_Register = _mm_loadu_ps(values);
	}

	void SIMDRegister128::Store(float* values) const
	{
		_mm_storeu_ps(values, m_Register);
	}

	void SIMDRegister128::SetZero()
	{
		m_Register = _mm_setzero_ps();
	}

	void SIMDRegister128::Add(const SIMDRegister128& reg)
	{
		m_Register = _mm_add_ps(m_Register, reg.m_Register);
	}

	void SIMDRegister128::Sub(const SIMDRegister128& reg)
	{
		m_Register = _mm_sub_ps(m_Register, reg.m_Register);
	}

	void SIMDRegister128::Mul(const SIMDRegister128& reg)
	{
		m_Register = _mm_mul_ps(m_Register, reg.m_Register);
	}

	void SIMDRegister128::Div(const SIMDRegister128& reg)
	{
		m_Register = _mm_div_ps(m_Register, reg.m_Register);
	}

	void SIMDRegister128::Sqrt()
	{
		m_Register = _mm_sqrt_ps(m_Register);
	}

	SIMDRegister128& SIMDRegister128::operator=(const SIMDRegister128& other)
	{
		m_Register = other.m_Register;
		return *this;
	}

	float& SIMDRegister128::operator[](size_t index)
	{
		if (index >= 4)
		{
			Logger::Log(LoggerChannel::Error, "A value was trying to be accessed with an index of {} in a SIMDRegister128", index);
			index = 0;
		}

#if defined PYRO_PLATFORM_WINDOWS
		return m_Register.m128_f32[index];
#endif

#if defined PYRO_PLATFORM_LINUX
		return m_Register[index];
#endif
	}

	SIMDRegister128 operator+(const SIMDRegister128& a, const SIMDRegister128& b)
	{
		return _mm_add_ps(a.GetRegisterBaseType(), b.GetRegisterBaseType());
	}

	SIMDRegister128 operator-(const SIMDRegister128& a, const SIMDRegister128& b)
	{
		return _mm_sub_ps(a.GetRegisterBaseType(), b.GetRegisterBaseType());
	}

	SIMDRegister128 operator*(const SIMDRegister128& a, const SIMDRegister128& b)
	{
		return _mm_mul_ps(a.GetRegisterBaseType(), b.GetRegisterBaseType());
	}

	SIMDRegister128 operator/(const SIMDRegister128& a, const SIMDRegister128& b)
	{
		return _mm_div_ps(a.GetRegisterBaseType(), b.GetRegisterBaseType());
	}

	SIMDRegister128& operator+=(SIMDRegister128& a, const SIMDRegister128& b)
	{
		a = _mm_add_ps(a.GetRegisterBaseType(), b.GetRegisterBaseType());
		return a;
	}

	SIMDRegister128& operator-=(SIMDRegister128& a, const SIMDRegister128& b)
	{
		a = _mm_sub_ps(a.GetRegisterBaseType(), b.GetRegisterBaseType());
		return a;
	}

	SIMDRegister128& operator*=(SIMDRegister128& a, const SIMDRegister128& b)
	{
		a = _mm_mul_ps(a.GetRegisterBaseType(), b.GetRegisterBaseType());
		return a;
	}

	SIMDRegister128& operator/=(SIMDRegister128& a, const SIMDRegister128& b)
	{
		a = _mm_div_ps(a.GetRegisterBaseType(), b.GetRegisterBaseType());
		return a;
	}
}