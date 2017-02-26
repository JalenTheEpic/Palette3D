/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_MATH_MATRIX3_
#define _CORE_MATH_MATRIX3_

#include <iostream>
#include <core/math/Vec3.h>

namespace Palette3D 
{
	//Here so we can friend Matrix 4
	class Matrix4;

	class Matrix3
	{
	protected:
		float mMat[3][3]; //[row] [col]

	public:
		Matrix3() {}

		Matrix3(float m[3][3])
		{
			memcpy(mMat, m, 9 * sizeof(float));
		}

		inline void swap(Matrix3& other)
		{
			std::swap(mMat[0][0], other.mMat[0][0]);
			std::swap(mMat[0][1], other.mMat[0][1]);
			std::swap(mMat[0][2], other.mMat[0][2]);
			std::swap(mMat[1][0], other.mMat[1][0]);
			std::swap(mMat[1][1], other.mMat[1][1]);
			std::swap(mMat[1][2], other.mMat[1][2]);
			std::swap(mMat[2][0], other.mMat[2][0]);
			std::swap(mMat[2][1], other.mMat[2][1]);
			std::swap(mMat[2][2], other.mMat[2][2]);
		}

		Matrix3(float e00, float e01, float e02,
				float e10, float e11, float e12,
				float e20, float e21, float e22) 
		{
			mMat[0][0] = e00;
			mMat[0][1] = e01;
			mMat[0][2] = e02;
			mMat[1][0] = e10;
			mMat[1][1] = e11;
			mMat[1][2] = e12;
			mMat[2][0] = e20;
			mMat[2][1] = e21;
			mMat[2][2] = e22;
		}
		
		~Matrix3()
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

		inline void operator= (const Matrix3& other) 
		{
			memcpy(mMat, other.mMat, 9*sizeof(float));
		}

		Matrix3 operator+ (const Matrix3& other) const;
		void operator+= (const Matrix3& other);

		Matrix3 operator- (const Matrix3& other) const;
		void operator-= (const Matrix3& other) ;

		Matrix3 operator* (float scalar) const;
		void operator*= (float scalar) ;
		Matrix3 operator* (const Matrix3& other) const;
		void operator*= (const Matrix3& other) ;

		Matrix3 operator- () const; //unary. can negate matrix 


		Vec3 operator* (const Vec3& other) const;

		
		bool operator!= (const Matrix3& other) const;
		bool operator== (const Matrix3& other) const;

		Matrix3 transpose() const;
		float determinant() const;

		Vec3 getRow(std::size_t row) const;
		void setRow(std::size_t row, Vec3 v);

		Vec3 getCol(std::size_t col) const;
		void setCol(std::size_t col, Vec3 v);


		friend std::ostream& operator<< (std::ostream& os, const Matrix3& m);
		

		friend Matrix4;

	public:
		static const Matrix3 ZERO;
		static const Matrix3 IDENTITY;
		

	};

}


#endif
