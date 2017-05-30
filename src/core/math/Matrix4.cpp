#include <core\math\Matrix4.h>
#include <assert.h>

#define PI 3.14159265358979323846f
namespace Palette3D 
{
	const Matrix4 Matrix4::IDENTITY(1.f, 0.f, 0.f,0.f,
									0.f, 1.f, 0.f,0.f,
									0.f, 0.f, 1.f,0.f,
									0.f, 0.f, 0.f, 1.f);

	const Matrix4 Matrix4::ZERO(0.f, 0.f, 0.f, 0.f,
								0.f, 0.f, 0.f, 0.f,
								0.f, 0.f, 0.f, 0.f,
								0.f, 0.f, 0.f, 0.f);

	Matrix4::Matrix4(F32 e00, F32 e01, F32 e02, F32 e03, F32 e10, F32 e11, F32 e12, F32 e13, F32 e20, F32 e21, F32 e22, F32 e23, F32 e30, F32 e31, F32 e32, F32 e33)
	{
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
	}

	Matrix4 Matrix4::operator+(const Matrix4 & other) const
	{
		return Matrix4(
			mMat[0] + other.mMat[0], mMat[4] + other.mMat[4], mMat[8] + other.mMat[8], mMat[12] + other.mMat[12],
			mMat[1] + other.mMat[1], mMat[5] + other.mMat[5], mMat[9] + other.mMat[9], mMat[13] + other.mMat[13],
			mMat[2] + other.mMat[2], mMat[6] + other.mMat[6], mMat[10] + other.mMat[10], mMat[14] + other.mMat[14],
			mMat[3] + other.mMat[3], mMat[7] + other.mMat[7], mMat[11] + other.mMat[11], mMat[15] + other.mMat[15]);
	}
	void Matrix4::operator+=(const Matrix4 & other)
	{
		*this = *this + other;
	}
	Matrix4 Matrix4::operator-(const Matrix4 & other) const
	{
		return Matrix4(
			mMat[0] - other.mMat[0], mMat[4] - other.mMat[4], mMat[8] - other.mMat[8], mMat[12] - other.mMat[12],
			mMat[1] - other.mMat[1], mMat[5] - other.mMat[5], mMat[9] - other.mMat[9], mMat[13] - other.mMat[13],
			mMat[2] - other.mMat[2], mMat[6] - other.mMat[6], mMat[10] - other.mMat[10], mMat[14] - other.mMat[14],
			mMat[3] - other.mMat[3], mMat[7] - other.mMat[7], mMat[11] - other.mMat[11], mMat[15] - other.mMat[15]);
	}
	void Matrix4::operator-=(const Matrix4 & other)
	{
		*this = *this - other;
	}
	Matrix4 Matrix4::operator*(F32 scalar) const
	{
		return Matrix4
			(mMat[0] * scalar, mMat[4] * scalar, mMat[8] * scalar, mMat[12] * scalar,
			 mMat[1] * scalar, mMat[5] * scalar, mMat[9] * scalar, mMat[13] * scalar,
			 mMat[2] * scalar, mMat[6] * scalar, mMat[10] * scalar, mMat[14] * scalar,
			 mMat[3] * scalar, mMat[7] * scalar, mMat[11] * scalar, mMat[15] * scalar);
	}
	void Matrix4::operator*=(F32 scalar)
	{
		*this = *this * scalar;
	}
	Matrix4 Matrix4::operator*(const Matrix4 & o) const
	{
		Matrix4 tmp;
		for (int i = 0; i<4; i++)
		{
			for (int j = 0; j<4; j++)
			{
				tmp.set(i,j, get(i,0) * o.get(0 ,j) + get(i,1) * o.get(1 ,j) + get(i,2) * o.get(2,j) + get(i,3) * o.get(3,j));
			}
		}
		return tmp;
	}
	void Matrix4::operator*=(const Matrix4 & other)
	{
		*this = *this * other;
	}
	Matrix4 Matrix4::operator-() const
	{
		return Matrix4( -mMat[0], -mMat[4], -mMat[8], -mMat[12],
						-mMat[1], -mMat[5], -mMat[9], -mMat[13],
						-mMat[2], -mMat[6], -mMat[10], -mMat[14],
						-mMat[3], -mMat[7], -mMat[11], -mMat[15]);
	}
	Vec4 Matrix4::operator*(const Vec4 & o) const
	{
		Vec4 v;
		v.x = mMat[0] * o.x + mMat[4] * o.y + mMat[8] * o.z + mMat[12] * o.w;
		v.y = mMat[1] * o.x + mMat[5] * o.y + mMat[9] * o.z + mMat[13] * o.w;
		v.z = mMat[2] * o.x + mMat[6] * o.y + mMat[10] * o.z + mMat[14] * o.w;
		v.w = mMat[3] * o.x + mMat[7] * o.y + mMat[11] * o.z + mMat[15] * o.w;
		
		return v;
	}
	Vec3 Matrix4::operator*(const Vec3 & o) const
	{
		Vec3 v;
		v.x = mMat[0] * o.x + mMat[4] * o.y + mMat[8] * o.z + mMat[12];
		v.y = mMat[1] * o.x + mMat[5] * o.y + mMat[9] * o.z + mMat[13];
		v.z = mMat[2] * o.x + mMat[6] * o.y + mMat[10] * o.z + mMat[14];
		

		return v;
	}
	bool Matrix4::operator!=(const Matrix4 & other) const
	{
		return !(*this == other);
	}
	bool Matrix4::operator==(const Matrix4 & other) const
	{
		for (int i = 0; i<16; i++)
		{
			
			if (mMat[i]!= other.mMat[i])
			{
				return false;
			}
			
		}
		return true;
	}
	Matrix4 Matrix4::transpose() const
	{
		Matrix4 tmp;
		for (int i = 0; i<4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				tmp.set(i,j, get(j,i));
			}
		}
		return tmp;
	}
	F32 Matrix4::determinant() const
	{
		/*
		----------------------------
		| a(0)  b(4)  c(8)   d(12) |
		| e(1)  f(5)  g(9)   h(13) |   det =  a(  f(kp - lo) - g(jp - ln) + h(jo - kn)  ) 
		| i(2)  j(6)  k(10)  l(14) |        - b(  e(kp - lo) - g(ip - lm) + h(io - km)  ) 
		| m(3)  n(7)  o(11)  p(15) |        + c(  e(jp - ln) - f(ip - lm) + h(in - jm)  ) 
		----------------------------        - d(  e(jo - kn) - f(io - km) + g(in - jm)  )  
		*/
		
		
			 //a * f(kp - lo) - g(jp - ln) + h(jo - kn)
		return mMat[0] * ((mMat[5] * (mMat[10] * mMat[15] - mMat[14] * mMat[11]))  
			                -(mMat[9] * (mMat[6] * mMat[15] - mMat[14] * mMat[7]))  
							+(mMat[13] * (mMat[6] * mMat[11] - mMat[10] * mMat[7])))  
			
			//b *  e(kp - lo) - g(ip - lm) + h(io - km) 
			- mMat[4] * ((mMat[1] * (mMat[10] * mMat[15] - mMat[14] * mMat[11]))  
						   -(mMat[9] * (mMat[2] * mMat[15] - mMat[14] * mMat[3]))  
						   +(mMat[13] * (mMat[2] * mMat[11] - mMat[10] * mMat[3]))) 
			
			//c *  e(jp - ln) - f(ip - lm) + h(in - jm)
			+ mMat[8] * ((mMat[1] * (mMat[6] * mMat[15] - mMat[14] * mMat[7]))
						   -(mMat[5] * (mMat[2] * mMat[15] - mMat[14] * mMat[3]))
						   +(mMat[13] * (mMat[2] * mMat[7] - mMat[6] * mMat[3])))
			
			//d * e(jo - kn) - f(io - km) + g(in - jm) 
			- mMat[12] * ((mMat[1] * (mMat[6] * mMat[11] - mMat[10] * mMat[7]))
						   -(mMat[5] * (mMat[2] * mMat[11] - mMat[10] * mMat[3]))
						   +(mMat[9] * (mMat[2] * mMat[7] - mMat[6] * mMat[3])));
			
			

	}

	F32 Matrix4::get(size_t row, size_t col) const
	{
		return mMat[row * 4 + col];
	}

	void Matrix4::set(size_t r, size_t c, F32 v) {
		mMat[r * 4 + c] = v;
	}

	Vec4 Matrix4::getRow(std::size_t row) const
	{
		if (row == 0) 
		{
			return  Vec4(mMat[0], mMat[4], mMat[8], mMat[12]);
		}
		else if (row == 1)
		{
			return Vec4(mMat[1], mMat[5], mMat[9], mMat[13]);
		}
		else if (row == 2) 
		{
			return Vec4(mMat[2], mMat[6], mMat[10], mMat[14]);
		}
		else if (row == 3) 
		{
			return Vec4(mMat[3], mMat[7], mMat[11], mMat[15]);
		}
		else 
		{
			return NULL;
		}
	}
	void Matrix4::setRow(std::size_t row, const Vec4 & v)
	{
		mMat[row * 4] = v.x;
		mMat[row * 4+1] = v.y;
		mMat[row * 4+2] = v.z;
		mMat[row * 4+3] = v.w;
	}
	
	Vec4 Matrix4::getCol(std::size_t col) const
	{
		if (col == 0)
		{
			return  Vec4(mMat[0], mMat[1], mMat[2], mMat[3]);
		}
		else if (col == 1)
		{
			return Vec4(mMat[4], mMat[5], mMat[6], mMat[7]);
		}
		else if (col == 2)
		{
			return Vec4(mMat[8], mMat[9], mMat[10], mMat[11]);
		}
		else if (col == 3)
		{
			return Vec4(mMat[12], mMat[13], mMat[14], mMat[15]);
		}
		else
		{
			return NULL;
		}
	}
	void Matrix4::setCol(std::size_t col, const Vec4 &  v)
	{
		mMat[col] = v.x;
		mMat[4 + col] = v.y;
		mMat[8 + col] = v.z;
		mMat[12+ col] = v.w;
	}
	Matrix4 Matrix4::translate(F32 a, F32 b, F32 c)
	{
		return Matrix4(
			1.f, 0.f, 0.f, a,
			0.f, 1.f, 0.f, b,
			0.f, 0.f, 1.f, c,
			0.f, 0.f, 0.f, 1.f);
	}
	Matrix4 Matrix4::scale(F32 x, F32 y, F32 z)
	{
		return Matrix4(
			x, 0.f, 0.f, 0.f,
			0.f, y, 0.f, 0.f,
			0.f, 0.f, z, 0.f,
			0.f, 0.f, 0.f, 1.f);
	}
	Matrix4 Matrix4::rotateX(F32 angle)
	{
		angle = (F32) angle * PI / 180.0f;
		
		return Matrix4(
			1.f, 0.f, 0.f, 0.f,
			0.f, cos(angle), -sin(angle), 0.f,
			0.f, sin(angle), cos(angle), 0.f,
			0.f, 0.f, 0.f, 1.f);
	}
	Matrix4 Matrix4::rotateY(F32 angle)
	{
		angle = (F32)angle * PI / 180.0f;
		return Matrix4(
			cos(angle), 0.f, sin(angle), 0.f,
			0.f, 1.f, 0.f, 0.f,
			-sin(angle), 0.f, cos(angle), 0.f,
			0.f, 0.f, 0.f, 1.f);
	}
	Matrix4 Matrix4::rotateZ(F32 angle)
	{
		angle = (F32)angle * PI / 180.0f;
		return Matrix4(
			cos(angle), -sin(angle), 0.f, 0.f,
			sin(angle), cos(angle), 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 0.f, 1.f);
	}
	Matrix4 Matrix4::rotation(F32 xrot, F32 yrot, F32 zrot)
	{
		Matrix4 tmp = Matrix4::IDENTITY;
		
		if (xrot)
		{
			tmp *= Matrix4::rotateX(xrot);
		}
		
		if (yrot)
		{
			tmp *= Matrix4::rotateY(yrot);
		}
		
		if (zrot)
		{
			tmp *= Matrix4::rotateZ(zrot);
		}

		return tmp;

	}
	Matrix4 Matrix4::ortho(I32 left, I32 right, I32 bottom, I32 top, F32 near, F32 far)
	{

		Matrix4 m = Matrix4::IDENTITY;
		m.set(0, 0, 2.f / (right - left));
		m.set(1, 1, 2.f / (top - bottom));
		m.set(2, 2, -2.f / (far - near));
		m.set(3, 0, (F32)-(right + left) / (right - left));
		m.set(3, 1, -(F32)(top + bottom) / (top - bottom));
		m.set(3, 2, -(F32)(far + near) / (far - near));
		return m;
		
	}
	Matrix4 Matrix4::perspective(F32 fov, F32 aspect, F32 near, F32 far)
	{
		assert(aspect != 0);
		assert(near != far);
		F32 rad = (F32)fov * PI / 180.0f;
		F32 tanhalf = tan(rad * 0.5f);

		Matrix4 m = Matrix4::IDENTITY;
		m.set(0, 0, 1 / (aspect * tanhalf));
		m.set(1, 1, 1 / (tanhalf));
		m.set(2, 2, -(far + near) / (far - near));
		m.set(2, 3, -1);
		m.set(3, 2, (2 * far * near)/( far - near));

		return m;
	}
	std::ostream & operator<<(std::ostream & os, const Matrix4 & m)
	{
		os << "| " << m[0] << "," << m[4] << "," << m[8] << "," << m[12] << " |" << std::endl;
		os << "| " << m[1] << "," << m[5] << "," << m[9] << "," << m[13] << " |" << std::endl;
		os << "| " << m[2] << "," << m[6] << "," << m[10] << "," << m[14] << " |" << std::endl;
		os << "| " << m[3] << "," << m[7] << "," << m[11] << "," << m[15] << " |" << std::endl;

		return os;
	}
}
