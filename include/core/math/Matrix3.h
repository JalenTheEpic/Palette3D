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

	/// <summary> 
	/// Class for Matrix 3.
	/// </summary> 
	class Matrix3
	{
	protected:
		F32 mMat[3][3]; //[row] [col]

	public:
		///<summary>
		///Default Consturctor for Matrix 3. Values are not initialized.
		///</summary>
		Matrix3() {}

		/// <param name="m">2D F32 array with values to fill matrix</param> 
		Matrix3(F32 m[3][3])
		{
			memcpy(mMat, m, 9 * sizeof(F32));
		}

		

		Matrix3(F32 e00, F32 e01, F32 e02,
				F32 e10, F32 e11, F32 e12,
				F32 e20, F32 e21, F32 e22) 
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

		inline const F32 * operator[] (size_t row) const 
		{
			return mMat[row];
		}

		inline  F32 * operator[] (size_t row) 
		{
			return mMat[row];
		}

		inline void operator= (const Matrix3& other) 
		{
			memcpy(mMat, other.mMat, 9*sizeof(F32));
		}

		Matrix3 operator+ (const Matrix3& other) const;
		void operator+= (const Matrix3& other);

		Matrix3 operator- (const Matrix3& other) const;
		void operator-= (const Matrix3& other) ;

		Matrix3 operator* (F32 scalar) const;
		void operator*= (F32 scalar) ;
		Matrix3 operator* (const Matrix3& other) const;
		void operator*= (const Matrix3& other) ;

		Matrix3 operator- () const;


		Vec3 operator* (const Vec3& other) const;

		
		bool operator!= (const Matrix3& other) const;
		bool operator== (const Matrix3& other) const;

		Matrix3 transpose() const;
		F32 determinant() const;

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
