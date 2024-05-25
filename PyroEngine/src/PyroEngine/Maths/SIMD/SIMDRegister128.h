#pragma once
#include <immintrin.h>

namespace PyroEngine
{
	class SIMDRegister128
	{
	private:
		__m128 m_Register;
	public:
		SIMDRegister128(bool setzero = false);
		SIMDRegister128(float* values);
		SIMDRegister128(__m128 base);
		~SIMDRegister128();

		__m128 GetRegisterBaseType() const;

		void Load(float* values);
		void Store(float* values) const;
		void SetZero();
		void Add(const SIMDRegister128& reg);
		void Sub(const SIMDRegister128& reg);
		void Mul(const SIMDRegister128& reg);
		void Div(const SIMDRegister128& reg);
		void Sqrt();

		SIMDRegister128& operator=(const SIMDRegister128& other);
		float& operator[](size_t index);
	};

	SIMDRegister128 operator+(const SIMDRegister128& a, const SIMDRegister128& b);
	SIMDRegister128 operator-(const SIMDRegister128& a, const SIMDRegister128& b);
	SIMDRegister128 operator*(const SIMDRegister128& a, const SIMDRegister128& b);
	SIMDRegister128 operator/(const SIMDRegister128& a, const SIMDRegister128& b);

	SIMDRegister128& operator+=(SIMDRegister128& a, const SIMDRegister128& b);
	SIMDRegister128& operator-=(SIMDRegister128& a, const SIMDRegister128& b);
	SIMDRegister128& operator*=(SIMDRegister128& a, const SIMDRegister128& b);
	SIMDRegister128& operator/=(SIMDRegister128& a, const SIMDRegister128& b);
}