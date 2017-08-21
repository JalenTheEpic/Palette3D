#include <core\math\Matrix4.h>
#include <assert.h>


namespace Palette3D {
	const Matrix4 Matrix4::IDENTITY(1.f, 0.f, 0.f,0.f,
									0.f, 1.f, 0.f,0.f,
									0.f, 0.f, 1.f,0.f,
									0.f, 0.f, 0.f, 1.f);

	const Matrix4 Matrix4::ZERO(0.f, 0.f, 0.f, 0.f,
								0.f, 0.f, 0.f, 0.f,
								0.f, 0.f, 0.f, 0.f,
								0.f, 0.f, 0.f, 0.f);

	Matrix4::Matrix4(F32 e00, F32 e01, F32 e02, F32 e03, F32 e10, F32 e11, F32 e12, F32 e13, F32 e20, F32 e21, F32 e22, F32 e23, F32 e30, F32 e31, F32 e32, F32 e33) {
		
			this->mMat[0] = e00;
			this->mMat[4] = e01;
			this->mMat[8] = e02;
			this->mMat[12] = e03;

			this->mMat[1] = e10;
			this->mMat[5] = e11;
			this->mMat[9] = e12;
			this->mMat[13] = e13;

			this->mMat[2] = e20;
			this->mMat[6] = e21;
			this->mMat[10] = e22;
			this->mMat[14] = e23;

			this->mMat[3] = e30;
			this->mMat[7] = e31;
			this->mMat[11] = e32;
			this->mMat[15] = e33;
		
	}

	Matrix4 Matrix4::operator+(const Matrix4 & other) const {
		return Matrix4(
			this->mMat[0] + other.mMat[0], this->mMat[4] + other.mMat[4], this->mMat[8] + other.mMat[8], this->mMat[12] + other.mMat[12],
			this->mMat[1] + other.mMat[1], this->mMat[5] + other.mMat[5], this->mMat[9] + other.mMat[9], this->mMat[13] + other.mMat[13],
			this->mMat[2] + other.mMat[2], this->mMat[6] + other.mMat[6], this->mMat[10] + other.mMat[10], this->mMat[14] + other.mMat[14],
			this->mMat[3] + other.mMat[3], this->mMat[7] + other.mMat[7], this->mMat[11] + other.mMat[11], this->mMat[15] + other.mMat[15]);
	}
	void Matrix4::operator+=(const Matrix4 & other) {
		*this = *this + other;
	}
	Matrix4 Matrix4::operator-(const Matrix4 & other) const {
		return Matrix4(
			this->mMat[0] - other.mMat[0], this->mMat[4] - other.mMat[4], this->mMat[8] - other.mMat[8], this->mMat[12] - other.mMat[12],
			this->mMat[1] - other.mMat[1], this->mMat[5] - other.mMat[5], this->mMat[9] - other.mMat[9], this->mMat[13] - other.mMat[13],
			this->mMat[2] - other.mMat[2], this->mMat[6] - other.mMat[6], this->mMat[10] - other.mMat[10], this->mMat[14] - other.mMat[14],
			this->mMat[3] - other.mMat[3], this->mMat[7] - other.mMat[7], this->mMat[11] - other.mMat[11], this->mMat[15] - other.mMat[15]);
	}
	void Matrix4::operator-=(const Matrix4 & other) {
		*this = *this - other;
	}
	Matrix4 Matrix4::operator*(F32 scalar) const {
		return Matrix4
			(this->mMat[0] * scalar, this->mMat[4] * scalar, this->mMat[8] * scalar, this->mMat[12] * scalar,
			 this->mMat[1] * scalar, this->mMat[5] * scalar, this->mMat[9] * scalar, this->mMat[13] * scalar,
			 this->mMat[2] * scalar, this->mMat[6] * scalar, this->mMat[10] * scalar, this->mMat[14] * scalar,
			 this->mMat[3] * scalar, this->mMat[7] * scalar, this->mMat[11] * scalar, this->mMat[15] * scalar);
	}
	void Matrix4::operator*=(F32 scalar) {
		*this = *this * scalar;
	}
	Matrix4 Matrix4::operator*(const Matrix4 & o) const {
		Matrix4 tmp = Matrix4::IDENTITY;
		//did this witout loops because I was bored
		tmp.mMat[0] = this->mMat[0] * o.mMat[0] + this->mMat[4] * o.mMat[1] + this->mMat[8] * o.mMat[2] + this->mMat[12] * o.mMat[3];
		tmp.mMat[4] = this->mMat[0] * o.mMat[4] + this->mMat[4] * o.mMat[5] + this->mMat[8] * o.mMat[6] + this->mMat[12] * o.mMat[7];
		tmp.mMat[8] = this->mMat[0] * o.mMat[8] + this->mMat[4] * o.mMat[9] + this->mMat[8] * o.mMat[10] + this->mMat[12] * o.mMat[11];
		tmp.mMat[12] = this->mMat[0] * o.mMat[12] + this->mMat[4] * o.mMat[13] + this->mMat[8] * o.mMat[14] + this->mMat[12] * o.mMat[15];

		tmp.mMat[1] = this->mMat[1] * o.mMat[0] + this->mMat[5] * o.mMat[1] + this->mMat[9] * o.mMat[2] + this->mMat[13] * o.mMat[3];
		tmp.mMat[5] = this->mMat[1] * o.mMat[4] + this->mMat[5] * o.mMat[5] + this->mMat[9] * o.mMat[6] + this->mMat[13] * o.mMat[7];
		tmp.mMat[9] = this->mMat[1] * o.mMat[8] + this->mMat[5] * o.mMat[9] + this->mMat[9] * o.mMat[10] + this->mMat[13] * o.mMat[11];
		tmp.mMat[13] = this->mMat[1] * o.mMat[12] + this->mMat[5] * o.mMat[13] + this->mMat[9] * o.mMat[14] + this->mMat[13] * o.mMat[15];

		tmp.mMat[2] = this->mMat[2] * o.mMat[0] + this->mMat[6] * o.mMat[1] + this->mMat[10] * o.mMat[2] + this->mMat[14] * o.mMat[3];
		tmp.mMat[6] = this->mMat[2] * o.mMat[4] + this->mMat[6] * o.mMat[5] + this->mMat[10] * o.mMat[6] + this->mMat[14] * o.mMat[7];
		tmp.mMat[10] = this->mMat[2] * o.mMat[8] + this->mMat[6] * o.mMat[9] + this->mMat[10] * o.mMat[10] + this->mMat[14] * o.mMat[11];
		tmp.mMat[14] = this->mMat[2] * o.mMat[12] + this->mMat[6] * o.mMat[13] + this->mMat[10] * o.mMat[14] + this->mMat[14] * o.mMat[15];

		tmp.mMat[3] = this->mMat[3] * o.mMat[0] + this->mMat[7] * o.mMat[1] + this->mMat[11] * o.mMat[2] + this->mMat[15] * o.mMat[3];
		tmp.mMat[7] = this->mMat[3] * o.mMat[4] + this->mMat[7] * o.mMat[5] + this->mMat[11] * o.mMat[6] + this->mMat[15] * o.mMat[7];
		tmp.mMat[11] = this->mMat[3] * o.mMat[8] + this->mMat[7] * o.mMat[9] + this->mMat[11] * o.mMat[10] + this->mMat[15] * o.mMat[11];
		tmp.mMat[15] = this->mMat[3] * o.mMat[12] + this->mMat[7] * o.mMat[13] + this->mMat[11] * o.mMat[14] + this->mMat[15] * o.mMat[15];

		return tmp;
	}
	void Matrix4::operator*=(const Matrix4 & other) {
		*this = *this * other;
	}
	Matrix4 Matrix4::operator-() const {
		return Matrix4( -this->mMat[0], -this->mMat[4], -this->mMat[8], -this->mMat[12],
						-this->mMat[1], -this->mMat[5], -this->mMat[9], -this->mMat[13],
						-this->mMat[2], -this->mMat[6], -this->mMat[10], -this->mMat[14],
						-this->mMat[3], -this->mMat[7], -this->mMat[11], -this->mMat[15]);
	}
	Vec4 Matrix4::operator*(const Vec4 & o) const {
		Vec4 v;
		v.x = this->mMat[0] * o.x + this->mMat[4] * o.y + this->mMat[8] * o.z + this->mMat[12] * o.w;
		v.y = this->mMat[1] * o.x + this->mMat[5] * o.y + this->mMat[9] * o.z + this->mMat[13] * o.w;
		v.z = this->mMat[2] * o.x + this->mMat[6] * o.y + this->mMat[10] * o.z + this->mMat[14] * o.w;
		v.w = this->mMat[3] * o.x + this->mMat[7] * o.y + this->mMat[11] * o.z + this->mMat[15] * o.w;
		
		return v;
	}
	Vec3 Matrix4::operator*(const Vec3 & o) const {
		Vec3 v;
		v.x = this->mMat[0] * o.x + this->mMat[4] * o.y + this->mMat[8] * o.z + this->mMat[12];
		v.y = this->mMat[1] * o.x + this->mMat[5] * o.y + this->mMat[9] * o.z + this->mMat[13];
		v.z = this->mMat[2] * o.x + this->mMat[6] * o.y + this->mMat[10] * o.z + this->mMat[14];
		

		return v;
	}
	bool Matrix4::operator!=(const Matrix4 & other) const {
		return !(*this == other);
	}
	bool Matrix4::operator==(const Matrix4 & other) const {
		for (int i = 0; i<16; i++) {
			
			if (this->mMat[i]!= other.mMat[i]) {
				return false;
			}
			
		}
		return true;
	}
	Matrix4 Matrix4::transpose() const {
		Matrix4 tmp;
		for (int i = 0; i<4; i++) {
			for (int j = 0; j < 4; j++) {
				tmp.set(i,j, get(j,i));
			}
		}
		return tmp;
	}
	F32 Matrix4::determinant() const {
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

	F32 Matrix4::get(size_t row, size_t col) const {
		assert(row<4 && col <4);
		return mMat[col* 4 + row];
	}

	void Matrix4::set(size_t r, size_t c, F32 v) {
		assert(r<4 && c <4);
		mMat[c * 4 + r] = v;
	}

	Vec4 Matrix4::getRow(std::size_t row) const {
		if (row == 0) {
			return  Vec4(mMat[0], mMat[4], mMat[8], mMat[12]);
		}
		else if (row == 1) {
			return Vec4(mMat[1], mMat[5], mMat[9], mMat[13]);
		}
		else if (row == 2) {
			return Vec4(mMat[2], mMat[6], mMat[10], mMat[14]);
		}
		else if (row == 3) {
			return Vec4(mMat[3], mMat[7], mMat[11], mMat[15]);
		}
		else {
			return NULL;
		}
	}
	void Matrix4::setRow(std::size_t row, const Vec4 & v) {
		mMat[row] = v.x;
		mMat[4 + row] = v.y;
		mMat[8 + row] = v.z;
		mMat[12 + row] = v.w;
	}
	
	Vec4 Matrix4::getCol(std::size_t col) const {
		if (col == 0) {
			return  Vec4(mMat[0], mMat[1], mMat[2], mMat[3]);
		}
		else if (col == 1) {
			return Vec4(mMat[4], mMat[5], mMat[6], mMat[7]);
		}
		else if (col == 2) {
			return Vec4(mMat[8], mMat[9], mMat[10], mMat[11]);
		}
		else if (col == 3) {
			return Vec4(mMat[12], mMat[13], mMat[14], mMat[15]);
		}
		else {
			return NULL;
		}
	}
	void Matrix4::setCol(std::size_t col, const Vec4 &  v) {
		
		mMat[col * 4] = v.x;
		mMat[col * 4 + 1] = v.y;
		mMat[col * 4 + 2] = v.z;
		mMat[col * 4 + 3] = v.w;
	}
	void Matrix4::setPos(F32 x, F32 y, F32 z) {
		mMat[12] = x;
		mMat[13] = y;
		mMat[14] = z;
	}
	void Matrix4::setScale(F32 x, F32 y, F32 z) {
		mMat[0] = x;
		mMat[5] = y;
		mMat[10] = z;
	}
	Matrix4 Matrix4::translate(F32 a, F32 b, F32 c) {
		return Matrix4(
			1.f, 0.f, 0.f, a,
			0.f, 1.f, 0.f, b,
			0.f, 0.f, 1.f, c,
			0.f, 0.f, 0.f, 1.f);
	}
	Matrix4 Matrix4::scale(F32 x, F32 y, F32 z) {
		return Matrix4(
			x, 0.f, 0.f, 0.f,
			0.f, y, 0.f, 0.f,
			0.f, 0.f, z, 0.f,
			0.f, 0.f, 0.f, 1.f);
	}
	Matrix4 Matrix4::rotateX(F32 angle) {
		angle = TORADIAN(angle);
		
		return Matrix4(
			1.f, 0.f, 0.f, 0.f,
			0.f, cos(angle), -sin(angle), 0.f,
			0.f, sin(angle), cos(angle), 0.f,
			0.f, 0.f, 0.f, 1.f);
	}
	Matrix4 Matrix4::rotateY(F32 angle) {
		angle = TORADIAN(angle);
		return Matrix4(
			cos(angle), 0.f, sin(angle), 0.f,
			0.f, 1.f, 0.f, 0.f,
			-sin(angle), 0.f, cos(angle), 0.f,
			0.f, 0.f, 0.f, 1.f);
	}
	Matrix4 Matrix4::rotateZ(F32 angle) {
		angle = TORADIAN(angle);
		return Matrix4(
			cos(angle), -sin(angle), 0.f, 0.f,
			sin(angle), cos(angle), 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 0.f, 1.f);
	}
	Matrix4 Matrix4::rotation(F32 xrot, F32 yrot, F32 zrot) {
		Matrix4 tmp = Matrix4::IDENTITY;
		
		if (xrot) {
			tmp *= Matrix4::rotateX(xrot);
		}
		
		if (yrot) {
			tmp *= Matrix4::rotateY(yrot);
		}
		
		if (zrot) {
			tmp *= Matrix4::rotateZ(zrot);
		}

		return tmp;

	}
	Matrix4 Matrix4::ortho(I32 left, I32 right, I32 bottom, I32 top, F32 near, F32 far) {
		//fix me
		Matrix4 m = Matrix4::IDENTITY;
		m.set(0, 0, 2.f / (right - left));
		m.set(1, 1, 2.f / (top - bottom));
		m.set(2, 2, -2.f / (far - near));
		m.set(3, 0, (F32)-(right + left) / (right - left));
		m.set(3, 1, -(F32)(top + bottom) / (top - bottom));
		m.set(3, 2, -(F32)(far + near) / (far - near));
		return m;
		
	}
	Matrix4 Matrix4::perspective(F32 fov, F32 aspect, F32 near, F32 far) {
		assert(aspect != 0);
		assert(near != far);
		F32 rad = TORADIAN(fov);
		F32 tanhalf = tan(rad * 0.5f);

		Matrix4 m = Matrix4::IDENTITY;
		m.set(0, 0, 1.f/ (aspect * tanhalf));
		m.set(1, 1, 1.f / (tanhalf));
		m.set(2, 2, -(far + near) / (far - near));
		m.set(3, 2, -1);
		m.set(2, 3, (2 * far * near)/( far - near));
		//std::cout << m << std::endl;
		return m;
	}
	Matrix4 Matrix4::lookAt(Vec3 pos, Vec3 target, Vec3 up) {
		Vec3 dir = (pos - target).normalize();
		Vec3 right = (up.cross(dir)).normalize();
		Vec3 camUp = dir.cross(right);
		Matrix4 m(
			right.x, right.y, right.z, 0,
			camUp.x, camUp.y, camUp.z, 0,
			dir.x, dir.y, dir.z, 0,
			0, 0, 0, 1);



		return m * Matrix4::translate(-pos.x, -pos.y, -pos.z);
	}
	std::ostream & operator<<(std::ostream & os, const Matrix4 & m) {
		os << "| " << m[0] << "," << m[4] << "," << m[8] << "," << m[12] << " |" << std::endl;
		os << "| " << m[1] << "," << m[5] << "," << m[9] << "," << m[13] << " |" << std::endl;
		os << "| " << m[2] << "," << m[6] << "," << m[10] << "," << m[14] << " |" << std::endl;
		os << "| " << m[3] << "," << m[7] << "," << m[11] << "," << m[15] << " |" << std::endl;

		return os;
	}
}
