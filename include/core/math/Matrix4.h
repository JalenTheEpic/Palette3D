/*
Palette3D
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
	
		
		

	public:
		F32 mMat[16];
		Matrix4() {}

		Matrix4(F32 m[4][4])
		{
			memcpy(mMat, m, 16 * sizeof(F32));
		}

		Matrix4(F32 m[16])
		{
			memcpy(mMat, m, 16 * sizeof(F32));
		}

		Matrix4(F32 e00, F32 e01, F32 e02, F32 e03,
				F32 e10, F32 e11, F32 e12, F32 e13,
				F32 e20, F32 e21, F32 e22, F32 e23,
				F32 e30, F32 e31, F32 e32, F32 e33)
		{
			mMat[0] = e00;
			mMat[4] = e01;
			mMat[8] = e02;
			mMat[12] = e03;

			mMat[1] = e10;
			mMat[5] = e11;
			mMat[9] = e12;
			mMat[13] = e13;

			mMat[2] = e20;
			mMat[6] = e21;
			mMat[10] = e22;
			mMat[14] = e23;

			mMat[3] = e30;
			mMat[7] = e31;
			mMat[11] = e32;
			mMat[15] = e33;
		}

		~Matrix4()
		{
			//delete[] mMat;
		}

		inline const F32 operator[] (size_t idx) const
		{
			return mMat[idx];
		}

		inline  F32 operator[] (size_t idx)
		{
			return mMat[idx];
		}

		inline Matrix4 & operator= (const Matrix4& other)
		{
			memcpy(mMat, other.mMat, 16 * sizeof(F32));
			return *this;

		}

		



		Matrix4 operator+ (const Matrix4& other) const;
		void operator+= (const Matrix4& other);

		Matrix4 operator- (const Matrix4& other) const;
		void operator-= (const Matrix4& other);

		Matrix4 operator* (F32 scalar) const;
		void operator*= (F32 scalar);
		Matrix4 operator* (const Matrix4& other) const;
		void operator*= (const Matrix4& other);

		Matrix4 operator- () const; //unary, negate matrix.


		Vec4 operator* (const Vec4& other) const;


		bool operator!= (const Matrix4& other) const;
		bool operator== (const Matrix4& other) const;

		Matrix4 transpose() const;
		F32 determinant() const;

		F32 get(size_t row, size_t col) const;
		void set(size_t row, size_t col, F32 val);
		Vec4 getRow(std::size_t row) const;
		void setRow(std::size_t row, const Vec4 &  v);

		Vec4 getCol(std::size_t col) const;
		void setCol(std::size_t col, const Vec4 &  v);

		

		friend std::ostream& operator<< (std::ostream& os, const Matrix4& m);

		

	public:
		static const Matrix4 ZERO;
		static const Matrix4 IDENTITY;

		static Matrix4 translate(F32 x = 0.f, F32 y = 0.f, F32 z = 0.f);

		static Matrix4 scale(F32 x=1.f, F32 y=1.f, F32 z=1.f);

		static Matrix4 rotateX(F32 angle);

		static Matrix4 rotateY(F32 angle);

		static Matrix4 rotateZ(F32 angle);

		static Matrix4 rotation(F32 xrot, F32 yrot, F32 zrot);
		
	


	};

}


#endif
