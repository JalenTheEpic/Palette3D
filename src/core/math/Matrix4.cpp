#include <core\math\Matrix4.h>
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

	Matrix4 Matrix4::operator+(const Matrix4 & other) const
	{
		return Matrix4(
			mMat[0][0] + other.mMat[0][0], mMat[0][1] + other.mMat[0][1], mMat[0][2] + other.mMat[0][2], mMat[0][3] + other.mMat[0][3],
			mMat[1][0] + other.mMat[1][0], mMat[1][1] + other.mMat[1][1], mMat[1][2] + other.mMat[1][2], mMat[1][3] + other.mMat[1][3],
			mMat[2][0] + other.mMat[2][0], mMat[2][1] + other.mMat[2][1], mMat[2][2] + other.mMat[2][2], mMat[2][3] + other.mMat[2][3],
			mMat[3][0] + other.mMat[3][0], mMat[3][1] + other.mMat[3][1], mMat[3][2] + other.mMat[3][2], mMat[3][3] + other.mMat[3][3]);
	}
	void Matrix4::operator+=(const Matrix4 & other)
	{
		*this = *this + other;
	}
	Matrix4 Matrix4::operator-(const Matrix4 & other) const
	{
		return Matrix4(
			mMat[0][0] - other.mMat[0][0], mMat[0][1] - other.mMat[0][1], mMat[0][2] - other.mMat[0][2], mMat[0][3] - other.mMat[0][3],
			mMat[1][0] - other.mMat[1][0], mMat[1][1] - other.mMat[1][1], mMat[1][2] - other.mMat[1][2], mMat[1][3] - other.mMat[1][3],
			mMat[2][0] - other.mMat[2][0], mMat[2][1] - other.mMat[2][1], mMat[2][2] - other.mMat[2][2], mMat[2][3] - other.mMat[2][3],
			mMat[3][0] - other.mMat[3][0], mMat[3][1] - other.mMat[3][1], mMat[3][2] - other.mMat[3][2], mMat[3][3] - other.mMat[3][3]);
	}
	void Matrix4::operator-=(const Matrix4 & other)
	{
		*this = *this - other;
	}
	Matrix4 Matrix4::operator*(F32 scalar) const
	{
		return Matrix4
			(mMat[0][0] * scalar, mMat[0][1] * scalar, mMat[0][2] * scalar, mMat[0][3] * scalar,
			 mMat[1][0] * scalar, mMat[1][1] * scalar, mMat[1][2] * scalar, mMat[1][3] * scalar,
			 mMat[2][0] * scalar, mMat[2][1] * scalar, mMat[2][2] * scalar, mMat[2][3] * scalar,
			 mMat[3][0] * scalar, mMat[3][1] * scalar, mMat[3][2] * scalar, mMat[3][3] * scalar);
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
				tmp.mMat[i][j] = mMat[i][0] * o.mMat[0][j] + mMat[i][1] * o.mMat[1][j] + mMat[i][2] * o.mMat[2][j] + mMat[i][3] * o.mMat[3][j];
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
		return Matrix4( -mMat[0][0], -mMat[0][1], -mMat[0][2], -mMat[0][3],
						-mMat[1][0], -mMat[1][1], -mMat[1][2], -mMat[1][3],
						-mMat[2][0], -mMat[2][1], -mMat[2][2], -mMat[2][3],
						-mMat[3][0], -mMat[3][1], -mMat[3][2], -mMat[3][3]);
	}
	Vec4 Matrix4::operator*(const Vec4 & other) const
	{
		Vec4 v;
		v.x = mMat[0][0] * v.x + mMat[0][1] * v.y + mMat[0][2] * v.z + mMat[0][3] * v.w;
		v.y = mMat[1][0] * v.x + mMat[1][1] * v.y + mMat[1][2] * v.z + mMat[1][3] * v.w;
		v.z = mMat[2][0] * v.x + mMat[2][1] * v.y + mMat[2][2] * v.z + mMat[2][3] * v.w;
		v.w = mMat[2][0] * v.x + mMat[2][1] * v.y + mMat[2][2] * v.z + mMat[3][3] * v.w;

		return v;
	}
	bool Matrix4::operator!=(const Matrix4 & other) const
	{
		return !(*this == other);
	}
	bool Matrix4::operator==(const Matrix4 & other) const
	{
		for (int i = 0; i<4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (mMat[i][j] != other.mMat[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	Matrix4 Matrix4::transpose() const
	{
		return Matrix4();
	}
	F32 Matrix4::determinant() const
	{
		/*
		----------------------------------
		| a(0,0)  b(0,1)  c(0,2)  d(0,3) |
		| e(1,0)  f(1,1)  g(1,2)  h(1,3) |   det =  a(  f(kp - lo) - g(jp - ln) + h(jo - kn)  ) 
		| i(2,0)  j(2,1)  k(2,2)  l(2,3) |        - b(  e(kp - lo) - g(ip - lm) + h(io - km)  ) 
		| m(3,0)  n(3,1)  o(3,2)  p(3,3) |        + c(  e(jp - ln) - f(ip - lm) + h(in - jm)  ) 
		----------------------------------        - d(  e(jo - kn) - f(io - km) + g(in - jm)  )  
		*/
		
		
			 //a
		return mMat[0][0] * ((mMat[1][1] * (mMat[2][2] * mMat[3][3] - mMat[2][3] * mMat[3][2]))  
			                -(mMat[1][2] * (mMat[2][1] * mMat[3][3] - mMat[2][3] * mMat[3][1]))  
							+(mMat[1][3] * (mMat[2][1] * mMat[3][2] - mMat[2][2] * mMat[3][1])))  
			
			//b
			- mMat[0][1] * ((mMat[1][0] * (mMat[2][2] * mMat[3][3] - mMat[2][3] * mMat[3][2]))  
						   -(mMat[1][2] * (mMat[2][0] * mMat[3][3] - mMat[2][3] * mMat[3][0]))  
						   +(mMat[1][3] * (mMat[2][0] * mMat[3][2] - mMat[2][2] * mMat[3][0]))) 
			
			//c
			+ mMat[0][2] * ((mMat[1][0] * (mMat[2][1] * mMat[3][3] - mMat[2][3] * mMat[3][1]))
						   -(mMat[1][1] * (mMat[2][0] * mMat[3][3] - mMat[2][3] * mMat[3][0]))
						   +(mMat[1][3] * (mMat[2][0] * mMat[3][1] - mMat[2][1] * mMat[3][0])))
			
			//d
			- mMat[0][3] * ((mMat[1][0] * (mMat[2][1] * mMat[3][2] - mMat[2][2] * mMat[3][1]))
						   -(mMat[1][1] * (mMat[2][0] * mMat[3][2] - mMat[2][2] * mMat[3][0]))
						   +(mMat[1][2] * (mMat[2][0] * mMat[3][1] - mMat[2][1] * mMat[3][0])));
			
			

	}


	Vec4 Matrix4::getRow(std::size_t row) const
	{
		return Vec4();
	}
	void Matrix4::setRow(std::size_t row, Vec4 v)
	{
	}
	
	Vec4 Matrix4::getCol(std::size_t col) const
	{
		return Vec4();
	}
	void Matrix4::setCol(std::size_t col, Vec4 v)
	{
	}
	std::ostream & operator<<(std::ostream & os, const Matrix4 & m)
	{
		os << "| " << m[0][0] << "," << m[0][1] << "," << m[0][2] << "," << m[0][3] << " |" << std::endl;
		os << "| " << m[1][0] << "," << m[1][1] << "," << m[1][2] << "," << m[1][3] << " |" << std::endl;
		os << "| " << m[2][0] << "," << m[2][1] << "," << m[2][2] << "," << m[2][3] << " |" << std::endl;
		os << "| " << m[3][0] << "," << m[3][1] << "," << m[3][2] << "," << m[3][3] << " |" << std::endl;

		return os;
	}
}
