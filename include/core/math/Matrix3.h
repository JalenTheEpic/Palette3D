/*
Palette3d
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_MATH_MATRIX3_
#define _CORE_MATH_MATRIX3_

#include <iostream>

namespace Palette3D 
{
	class Matrix3
	{
	private:
		float mMatrix[3][3]; //[row] [col]

	public:
		Matrix3();

		Matrix3(float m[3][3])
		{
			memcpy(mMatrix, m, 9 * sizeof(float));
		}

		inline void swap(Matrix3& other)
		{
			std::swap(mMatrix[0][0], other.mMatrix[0][0]);
			std::swap(mMatrix[0][1], other.mMatrix[0][1]);
			std::swap(mMatrix[0][2], other.mMatrix[0][2]);
			std::swap(mMatrix[1][0], other.mMatrix[1][0]);
			std::swap(mMatrix[1][1], other.mMatrix[1][1]);
			std::swap(mMatrix[1][2], other.mMatrix[1][2]);
			std::swap(mMatrix[2][0], other.mMatrix[2][0]);
			std::swap(mMatrix[2][1], other.mMatrix[2][1]);
			std::swap(mMatrix[2][2], other.mMatrix[2][2]);
		}

		Matrix3(float e00, float e01, float e02,
				float e10, float e11, float e12,
				float e20, float e21, float e22) 
		{
			mMatrix[0][0] = e00;
			mMatrix[0][1] = e01;
			mMatrix[0][2] = e02;
			mMatrix[1][0] = e10;
			mMatrix[1][1] = e11;
			mMatrix[1][2] = e12;
			mMatrix[2][0] = e20;
			mMatrix[2][1] = e21;
			mMatrix[2][2] = e22;
		}
		
		~Matrix3()
		{
			delete[] mMatrix;
		}


		



	};

}


#endif
