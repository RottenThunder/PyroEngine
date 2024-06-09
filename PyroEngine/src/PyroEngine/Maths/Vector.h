#pragma once
#include <cmath>
#include <cstring>
#include "MathF.h"

namespace PyroEngine
{
	template<size_t S>
	struct Vector
	{
		float components[S];

		Vector() = default;

		void Reset() { std::memset(&components, 0, S * sizeof(float)); }

		void Add(Vector<S>& v)
		{
			for (size_t i = 0; i < S; i++)
				components[i] += v.components[i];
		}

		void Sub(Vector<S>& v)
		{
			for (size_t i = 0; i < S; i++)
				components[i] -= v.components[i];
		}

		float Dot(Vector<S>& v)
		{
			float sqComponents[S];
			for (size_t i = 0; i < S; i++)
				sqComponents[i] = components[i] * v.components[i];
			for (size_t i = 1; i < S; i++)
				sqComponents[0] += sqComponents[i];
			return sqComponents[0];
		}

		float SqMagnitude()
		{
			float sqComponents[S];
			for (size_t i = 0; i < S; i++)
				sqComponents[i] = components[i] * components[i];
			for (size_t i = 1; i < S; i++)
				sqComponents[0] += sqComponents[i];
			return sqComponents[0];
		}

		float Magnitude()
		{
			float sqComponents[S];
			for (size_t i = 0; i < S; i++)
				sqComponents[i] = components[i] * components[i];
			for (size_t i = 1; i < S; i++)
				sqComponents[0] += sqComponents[i];
			return std::sqrt(sqComponents[0]);
		}

		void Normalise()
		{
			float magnitude = Magnitude();
			for (size_t i = 0; i < S; i++)
				components[i] /= magnitude;
		}
	};

	template<>
	struct Vector<2>
	{
		float x, y;

		Vector();
		Vector(float ix, float iy);

		void Reset();

		void Add(Vector<2>& v);
		void Sub(Vector<2>& v);

		float Dot(Vector<2>& v);

		float SqMagnitude();
		float Magnitude();

		void Normalise();
	};

	template<>
	struct Vector<3>
	{
		float x, y, z;

		Vector();
		Vector(float ix, float iy, float iz);

		void Reset();

		void Add(Vector<3>& v);
		void Sub(Vector<3>& v);

		float Dot(Vector<3>& v);

		float SqMagnitude();
		float Magnitude();

		void Normalise();
	};

	template<>
	struct Vector<4>
	{
		float x, y, z, w;

		Vector();
		Vector(float ix, float iy, float iz, float iw);

		void Reset();

		void Add(Vector<4>& v);
		void Sub(Vector<4>& v);

		float Dot(Vector<4>& v);

		float SqMagnitude();
		float Magnitude();

		void Normalise();
	};

	inline Vector<2>::Vector()
	{
	}

	inline Vector<2>::Vector(float ix, float iy)
		: x(ix), y(iy)
	{
	}

	inline void Vector<2>::Reset()
	{
		MathF::ResetVector2(&x);
	}

	inline void Vector<2>::Add(Vector<2>& v)
	{
		MathF::AddVector2(&x, &x, &v.x);
	}

	inline void Vector<2>::Sub(Vector<2>& v)
	{
		MathF::SubVector2(&x, &x, &v.x);
	}

	inline float Vector<2>::Dot(Vector<2>& v)
	{
		return MathF::DotVector2(&x, &v.x);
	}

	inline float Vector<2>::SqMagnitude()
	{
		return MathF::SqMagnitudeVector2(&x);
	}

	inline float Vector<2>::Magnitude()
	{
		return MathF::MagnitudeVector2(&x);
	}

	inline void Vector<2>::Normalise()
	{
		return MathF::NormaliseVector2(&x, &x);
	}

	inline Vector<3>::Vector()
	{
	}

	inline Vector<3>::Vector(float ix, float iy, float iz)
		: x(ix), y(iy), z(iz)
	{
	}

	inline void Vector<3>::Reset()
	{
		MathF::ResetVector3(&x);
	}

	inline void Vector<3>::Add(Vector<3>& v)
	{
		MathF::AddVector3(&x, &x, &v.x);
	}

	inline void Vector<3>::Sub(Vector<3>& v)
	{
		MathF::SubVector3(&x, &x, &v.x);
	}

	inline float Vector<3>::Dot(Vector<3>& v)
	{
		return MathF::DotVector3(&x, &v.x);
	}

	inline float Vector<3>::SqMagnitude()
	{
		return MathF::SqMagnitudeVector3(&x);
	}

	inline float Vector<3>::Magnitude()
	{
		return MathF::MagnitudeVector3(&x);
	}

	inline void Vector<3>::Normalise()
	{
		return MathF::NormaliseVector3(&x, &x);
	}

	inline Vector<4>::Vector()
	{
	}

	inline Vector<4>::Vector(float ix, float iy, float iz, float iw)
		: x(ix), y(iy), z(iz), w(iw)
	{
	}

	inline void Vector<4>::Reset()
	{
		MathF::ResetVector4(&x);
	}

	inline void Vector<4>::Add(Vector<4>& v)
	{
		MathF::AddVector4(&x, &x, &v.x);
	}

	inline void Vector<4>::Sub(Vector<4>& v)
	{
		MathF::SubVector4(&x, &x, &v.x);
	}

	inline float Vector<4>::Dot(Vector<4>& v)
	{
		return MathF::DotVector4(&x, &v.x);
	}

	inline float Vector<4>::SqMagnitude()
	{
		return MathF::SqMagnitudeVector4(&x);
	}

	inline float Vector<4>::Magnitude()
	{
		return MathF::MagnitudeVector4(&x);
	}

	inline void Vector<4>::Normalise()
	{
		return MathF::NormaliseVector4(&x, &x);
	}

	typedef Vector<2> Vector2;
	typedef Vector<3> Vector3;
	typedef Vector<4> Vector4;
}