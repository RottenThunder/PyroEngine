#pragma once
#include <cmath>
#include <cstring>
#include "MathF.h"

namespace PyroEngine
{
	//Class Representing an RxC Matrix in Column Major Order
	template<size_t R, size_t C>
	struct Matrix
	{
		union
		{
			float components[R * C];
			float componentsMD[C][R];
		};

		Matrix() = default;

		void Reset() { std::memset(&components, 0, R * C * sizeof(float)); }

		void Add(Matrix<R, C>& m)
		{
			for (size_t i = 0; i < R * C; i++)
				components[i] += m.components[i];
		}

		void Sub(Matrix<R, C>& m)
		{
			for (size_t i = 0; i < R * C; i++)
				components[i] -= m.components[i];
		}

		template<size_t mC>
		Matrix<R, mC> Multiply(Matrix<C, mC>& m)
		{
			Matrix<R, mC> output;

			for (size_t y = 0; y < R; y++)
			{
				for (size_t x = 0; x < mC; x++)
				{
					float sqComponents[C];
					for (size_t i = 0; i < C; i++)
						sqComponents[i] = componentsMD[i][y] * m.componentsMD[x][i];
					for (size_t i = 1; i < C; i++)
						sqComponents[0] += sqComponents[i];
					
					output.componentsMD[x][y] = sqComponents[0];
				}
			}

			return output;
		}
	};

	typedef Matrix<2, 2> Matrix2x2;
	typedef Matrix<2, 3> Matrix2x3;
	typedef Matrix<2, 4> Matrix2x4;
	typedef Matrix<3, 2> Matrix3x2;
	typedef Matrix<3, 3> Matrix3x3;
	typedef Matrix<3, 4> Matrix3x4;
	typedef Matrix<4, 2> Matrix4x2;
	typedef Matrix<4, 3> Matrix4x3;
	typedef Matrix<4, 4> Matrix4x4;

	//Creates a translation matrix that can be used for translating a Vector4 by x and y units
	Matrix4x4 CreateTranslation(float x, float y)
	{
		//[1, 0, 0, x]
		//[0, 1, 0, y]
		//[0, 0, 1, 0]
		//[0, 0, 0, 1]

		Matrix4x4 translation;
		translation.Reset();
		translation.components[0] = 1.0f;
		translation.components[5] = 1.0f;
		translation.components[10] = 1.0f;
		translation.components[12] = x;
		translation.components[13] = y;
		translation.components[15] = 1.0f;
		return translation;
	}

	//Creates a scale matrix that can be used for scaling Vector4s up by a factor of sx and sy
	Matrix4x4 CreateScale(float sx, float sy)
	{
		//[sx,  0, 0, 0]
		//[ 0, sy, 0, 0]
		//[ 0,  0, 1, 0]
		//[ 0,  0, 0, 1]

		Matrix4x4 scale;
		scale.Reset();
		scale.components[0] = sx;
		scale.components[5] = sy;
		scale.components[10] = 1.0f;
		scale.components[15] = 1.0f;
		return scale;
	}

	//Creates a rotation matrix that can be used to rotate Vector4s about the z-axis (the only rotation that is noticable in 2D)
	Matrix4x4 CreateRotation(float radians)
	{
		//[cos(radians), -sin(radians), 0, 0]
		//[sin(radians),  cos(radians), 0, 0]
		//[           0,             0, 1, 0]
		//[           0,             0, 0, 1]

		float sinAngle = std::sin(radians);
		float cosAngle = std::cos(radians);
		Matrix4x4 rotation;
		rotation.Reset();
		rotation.components[0] = cosAngle;
		rotation.components[1] = sinAngle;
		rotation.components[4] = -sinAngle;
		rotation.components[5] = cosAngle;
		rotation.components[10] = 1.0f;
		rotation.components[15] = 1.0f;
		return rotation;
	}

	//Creates a view matrix which can be used for 2D camera orientation
	Matrix4x4 CreateView(float x = 0.0f, float y = 0.0f, float radians = 0.0f)
	{
		//[cos(radians), -sin(radians),  0, -x]
		//[sin(radians),  cos(radians),  0, -y]
		//[           0,             0,  1, -1]
		//[           0,             0,  0,  1]

		float sinAngle = std::sin(radians);
		float cosAngle = std::cos(radians);
		Matrix4x4 view;
		view.Reset();
		view.components[0] = cosAngle;
		view.components[1] = sinAngle;
		view.components[4] = -sinAngle;
		view.components[5] = cosAngle;
		view.components[10] = 1.0f;
		view.components[12] = -x;
		view.components[13] = -y;
		view.components[14] = -1.0f;
		view.components[15] = 1.0f;
		return view;
	}

	//Creates an orthographic projection matrix which will have the world coordinates at the edges of the camera
	Matrix4x4 CreateProjection(float left = -1.0f, float right = 1.0f, float bottom = -1.0f, float top = 1.0f)
	{
		//[2/(right - left),                0,  0, -(right + left)/(right - left)]
		//[               0, 2/(top - bottom),  0, -(top + bottom)/(top - bottom)]
		//[               0,                0, -1,                              0]
		//[               0,                0,  0,                              1]

		Matrix4x4 ortho;
		ortho.Reset();
		ortho.components[0] = 2.0f / (right - left);
		ortho.components[5] = 2.0f / (top - bottom);
		ortho.components[10] = -1.0f;
		ortho.components[15] = 1.0f;
		ortho.components[12] = -(right + left) / (right - left);
		ortho.components[13] = -(top + bottom) / (top - bottom);
		return ortho;
	}

	//Creates an view-projection matrix which is the equivalent of a projection matrix times a view matrix
	Matrix4x4 CreateViewProjection(float left = -1.0f, float right = 1.0f, float bottom = -1.0f, float top = 1.0f, float x = 0.0f, float y = 0.0f, float radians = 0.0f)
	{
		//[2cos(radians)/(right - left), -2sin(radians)/(right - left),  0, -(2x + right + left)/(right - left)]
		//[2sin(radians)/(top - bottom),  2cos(radians)/(top - bottom),  0, -(2y + top + bottom)/(top - bottom)]
		//[                           0,                             0, -1,                                   1]
		//[                           0,                             0,  0,                                   1]

		float twoTimesSinAngle = 2.0f * std::sin(radians);
		float twoTimesCosAngle = 2.0f * std::cos(radians);
		float rightMinusLeft = right - left;
		float topMinusBottom = top - bottom;
		Matrix4x4 viewProjection;
		viewProjection.Reset();
		viewProjection.components[0] = twoTimesCosAngle / rightMinusLeft;
		viewProjection.components[1] = twoTimesSinAngle / topMinusBottom;
		viewProjection.components[4] = -twoTimesSinAngle / rightMinusLeft;
		viewProjection.components[5] = twoTimesCosAngle / topMinusBottom;
		viewProjection.components[10] = -1.0f;
		viewProjection.components[12] = ((-2.0f * x) - right - left) / rightMinusLeft;
		viewProjection.components[13] = ((-2.0f * y) - top - bottom) / topMinusBottom;
		viewProjection.components[14] = 1.0f;
		viewProjection.components[15] = 1.0f;
		return viewProjection;
	}
}