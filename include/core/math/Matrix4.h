/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_MATH_MATRIX4_
#define _CORE_MATH_MATRIX4_

#include <iostream>
#include <core/math/Vec3.h>
#include <core/math/Vec4.h>


namespace Palette3D
{
	
	class Matrix4
	{
	private:
		float mMat[4][4]; //[row] [col]

	public:
		Matrix4() {}

		Matrix4(float m[4][4])
		{
			memcpy(mMat, m, 16 * sizeof(float));
		}

		inline void swap(Matrix4& other)
		{
			std::swap(mMat[0][0], other.mMat[0][0]);
			std::swap(mMat[0][1], other.mMat[0][1]);
			std::swap(mMat[0][2], other.mMat[0][2]);
			std::swap(mMat[0][3], other.mMat[0][3]);

			std::swap(mMat[1][0], other.mMat[1][0]);
			std::swap(mMat[1][1], other.mMat[1][1]);
			std::swap(mMat[1][2], other.mMat[1][2]);
			std::swap(mMat[1][3], other.mMat[1][3]);

			std::swap(mMat[2][0], other.mMat[2][0]);
			std::swap(mMat[2][1], other.mMat[2][1]);
			std::swap(mMat[2][2], other.mMat[2][2]);
			std::swap(mMat[2][3], other.mMat[2][3]);

			std::swap(mMat[3][0], other.mMat[3][0]);
			std::swap(mMat[3][1], other.mMat[3][1]);
			std::swap(mMat[3][2], other.mMat[3][2]);
			std::swap(mMat[3][3], other.mMat[3][3]);
		}

		Matrix4(float e00, float e01, float e02, float e03,
				float e10, float e11, float e12, float e13,
				float e20, float e21, float e22, float e23,
				float e30, float e31, float e32, float e33)
		{
			mMat[0][0] = e00;
			mMat[0][1] = e01;
			mMat[0][2] = e02;
			mMat[0][3] = e03;

			mMat[1][0] = e10;
			mMat[1][1] = e11;
			mMat[1][2] = e12;
			mMat[1][3] = e13;

			mMat[2][0] = e20;
			mMat[2][1] = e21;
			mMat[2][2] = e22;
			mMat[2][3] = e23;

			mMat[3][0] = e30;
			mMat[3][1] = e31;
			mMat[3][2] = e32;
			mMat[3][3] = e33;
		}

		~Matrix4()
		{
			//delete[] mMat;
		}

		inline const float * operator[] (size_t row) const
		{
			return mMat[row];
		}

		inline  float * operator[] (size_t row)
		{
			return mMat[row];
		}

		inline Matrix4 & operator= (const Matrix4& other)
		{
			memcpy(mMat, other.mMat, 16 * sizeof(float));
			return *this;

		}

		

	public:
		static const Matrix4 ZERO;
		static const Matrix4 IDENTITY;


	};

}


#endif
