#include <core/math/Matrix3.h>
namespace Palette3D {
	const Matrix3 Matrix3::IDENTITY(1.f,0.f,0.f,
									0.f,1.f,0.f,
									0.f,0.f,1.f);

	const Matrix3 Matrix3::ZERO(0.f, 0.f, 0.f, 
								0.f, 0.f, 0.f, 
								0.f, 0.f, 0.f);

	std::ostream & operator<<(std::ostream & os, const Matrix3 & m) {
		os << "| " << m[0][0] << "," << m[0][1] << "," << m[0][2] << " |" << std::endl;
		os << "| " << m[1][0] << "," << m[1][1] << "," << m[1][2] << " |" << std::endl;
		os << "| " << m[2][0] << "," << m[2][1] << "," << m[2][2] << " |" << std::endl;

		return os;
	}


	Matrix3 Matrix3::operator+(const Matrix3 & other) const {
	
		return Matrix3( mMat[0][0] + other.mMat[0][0], mMat[0][1] + other.mMat[0][1], mMat[0][2] + other.mMat[0][2],
						mMat[1][0] + other.mMat[1][0], mMat[1][1] + other.mMat[1][1], mMat[1][2] + other.mMat[1][2],
						mMat[2][0] + other.mMat[2][0], mMat[2][1] + other.mMat[2][1], mMat[2][2] + other.mMat[2][2]);
	}

	void Matrix3::operator+=(const Matrix3 & other) {
		*this = *this + other;
	}


	Matrix3 Matrix3::operator-(const Matrix3 & other) const {
		return Matrix3( mMat[0][0] - other.mMat[0][0], mMat[0][1] - other.mMat[0][1], mMat[0][2] - other.mMat[0][2],
						mMat[1][0] - other.mMat[1][0], mMat[1][1] - other.mMat[1][1], mMat[1][2] - other.mMat[1][2],
						mMat[2][0] - other.mMat[2][0], mMat[2][1] - other.mMat[2][1], mMat[2][2] - other.mMat[2][2]);
	}

	void Matrix3::operator-=(const Matrix3 & other) {
		*this = *this - other;
	}


	Matrix3 Matrix3::operator*(F32 scalar) const {

		return Matrix3( mMat[0][0] * scalar, mMat[0][1] * scalar, mMat[0][2] * scalar,
						mMat[1][0] * scalar, mMat[1][1] * scalar, mMat[1][2] * scalar,
						mMat[2][0] * scalar, mMat[2][1] * scalar, mMat[2][2] * scalar);
	}

	void Matrix3::operator*=(F32 scalar) {

		*this = *this * scalar;
	}


	Matrix3 Matrix3::operator*(const Matrix3 & o) const {
		//too lazy to write this out
		Matrix3 tmp;
		for (int i = 0; i<3;i++) {
			for (int j = 0; j<3; j++) {
				tmp.mMat[i][j] = mMat[i][0] * o.mMat[0][j] + mMat[i][1] * o.mMat[1][j] + mMat[i][2] * o.mMat[2][j];
			}
		}
		return tmp;
	}

	void Matrix3::operator*=(const Matrix3 & other) {
		*this = *this * other;
	}


	Matrix3 Matrix3::operator-() const {
		return Matrix3( -mMat[0][0], -mMat[0][1], -mMat[0][2],
						-mMat[1][0], -mMat[1][1], -mMat[1][2],
						-mMat[2][0], -mMat[2][1], -mMat[2][2]);
	}


	Vec3 Matrix3::operator*(const Vec3 & other) const {
		Vec3 v;
		v.x = mMat[0][0] * v.x + mMat[0][1] * v.y + mMat[0][2] * v.z;
		v.y = mMat[1][0] * v.x + mMat[1][1] * v.y + mMat[1][2] * v.z;
		v.z = mMat[2][0] * v.x + mMat[2][1] * v.y + mMat[2][2] * v.z;

		return v;

	}


	bool Matrix3::operator!=(const Matrix3 & other) const {
		return !(*this == other);
	}

	bool Matrix3::operator==(const Matrix3 & other) const {
		for (int i = 0; i<3; i++) {
			for (int j = 0; j < 3; j++) {
				if (mMat[i][j] != other.mMat[i][j]) {
					return false;
				}
			}
		}
		return true;
	}


	Matrix3 Matrix3::transpose() const {
		F32 tmp[3][3];
		for (int i = 0; i<3; i++) {
			for (int j = 0; j < 3; j++) {
				tmp[i][j] = mMat[j][i];
			}
		}
		return Matrix3(tmp);
	}


	F32 Matrix3::determinant() const {
		/*
			 -------
			|a  b  c|
			|d  e  f|
			|g  h  i|
			 -------
		*/
		F32 det = 0.0f;
		det += mMat[0][0] * mMat[1][1] * mMat[2][2];//aei
		det += mMat[0][1] * mMat[1][2] * mMat[2][0];//+bfg
		det += mMat[0][2] * mMat[1][0] * mMat[2][1];//+cdh

		det -= mMat[0][2] * mMat[1][1] * mMat[2][0];//-ceg
		det -= mMat[0][1] * mMat[1][0] * mMat[2][2];//-bdi
		det -= mMat[0][0] * mMat[1][2] * mMat[2][1];//-afh
		
		return det;
	}


	Vec3 Matrix3::getRow(std::size_t row) const {
		return Vec3(mMat[row][0], mMat[row][1], mMat[row][2]);
	}


	void Matrix3::setRow(std::size_t row, Vec3 v) {
		mMat[row][0] = v.x;
		mMat[row][1] = v.y;
		mMat[row][2] = v.z;
	}


	Vec3 Matrix3::getCol(std::size_t col) const {
		return Vec3(mMat[0][col], mMat[1][col], mMat[2][col]);
	}


	void Matrix3::setCol(std::size_t col, Vec3 v) {
		mMat[0][col] = v.x;
		mMat[1][col] = v.y;
		mMat[2][col] = v.z;
	}
}
