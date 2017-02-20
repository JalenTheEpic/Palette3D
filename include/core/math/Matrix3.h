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
		
		~Matrix3();

	};

}


#endif
