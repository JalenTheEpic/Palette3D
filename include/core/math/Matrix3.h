/*
Palette3D
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

		//the following comment is more for testing than it is to be actually useful
		
		/// <summary>
		/// Constructor for Matrix 3 that takes in 9 float values
		/// </summary>
		/// <example> 
		/// This sample shows how to call the Matrix 3 constructor.
		/// <code>
		/// class TestClass 
		/// {
		///     static int Main() 
		///     {
		///         Palette3D::Matrix3 m(1.f, 2.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f);
		///			//|1, 2, 0|
		///			//|0, 1, 0|
		///			//|0, 0, 1|
		///     }
		/// }
		/// </code>
		/// </example>
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
		
		/// <summary>
		/// Returns a pointer to a specified row. This is the const overide.
		/// </summary>
		inline const F32 * operator[] (size_t row) const 
		{
			return mMat[row];
		}

		/// <summary>
		/// Returns a pointer to a specified row. 
		/// </summary>
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
		
		
		/// <summary>
		/// Returns the transposed version of this matrix 
		/// </summary>
		Matrix3 transpose() const;

		/// <summary>
		/// Returns the determinant of this matrix
		/// </summary>
		F32 determinant() const;

		/// <summary>
		/// Returns the a vector 3 of the row
		/// </summary>
		Vec3 getRow(std::size_t row) const;


		/// <summary>
		/// Returns the a vector 3 of the row
		/// </summary>
		Vec3 getCol(std::size_t col) const;

		/// <summary>
		/// Sets the specified row of this matrix to the contents of the vector
		/// </summary>
		void setRow(std::size_t row, Vec3 v);

		

		/// <summary>
		/// Sets the specified column of this matrix to the contents of the vector 
		/// </summary>
		void setCol(std::size_t col, Vec3 v);

		/// <summary>
		///  << Override to allow matrix to be printed through std::cout
		/// </summary>
		friend std::ostream& operator<< (std::ostream& os, const Matrix3& m);
		

		friend Matrix4;

	public:
		static const Matrix3 ZERO;
		static const Matrix3 IDENTITY;
		

	};

}


#endif
