/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_MATH_VEC4_
#define _CORE_MATH_VEC4_
#include <core\math\Vec3.h>
#include <iostream>

namespace Palette3D
{
	class Vec4
	{
		/// Member variables.
	public:
		F32 mX;
		F32 mY;
		F32 mZ;
		F32 mW;

		/// Constructor and Destructor.
	public:
		inline Vec4(const F32 x = 0.0f, const F32 y = 0.0f, const F32 z = 0.0f, const F32 w = 0.0f) : mX(x), mY(y), mZ(z), mW(w) {}
		inline Vec4(const Vec4& v) : mX(v.mX), mY(v.mY), mZ(v.mZ), mW(v.mW) {}
		inline Vec4(const Vec3& v) : mX(v.mX), mY(v.mY), mZ(v.mZ), mW(0) {}
		inline Vec4(const Vec2& v) : mX(v.mX), mY(v.mY), mZ(0), mW(0) {}
		~Vec4() {}

		/// Operator functions.
	public:
		inline Vec4 operator+(const Vec4& rhs) const { return Vec4(mX + rhs.mX, mY + rhs.mY, mZ + rhs.mZ, mW + rhs.mW); }
		inline Vec4 operator-(const Vec4& rhs) const { return Vec4(mX - rhs.mX, mY - rhs.mY, mZ - rhs.mZ, mW - rhs.mW); }
		inline Vec4 operator*(const F32& rhs) const { return Vec4(mX * rhs, mY * rhs, mZ * rhs, mW * rhs); }

		inline void operator=(const Vec4& rhs) { mX = rhs.mX; mY = rhs.mY; mZ = rhs.mZ; mW = rhs.mW; }

		inline void operator+=(const Vec4& rhs) { mX += rhs.mX; mY += rhs.mY; mZ += rhs.mZ; mW += rhs.mW; }
		inline void operator-=(const Vec4& rhs) { mX -= rhs.mX; mY -= rhs.mY; mZ -= rhs.mZ; mW -= rhs.mW; }
		inline void operator*=(const F32& rhs) { mX *= rhs; mY *= rhs; mZ *= rhs; mW *= rhs; }

		inline F32 operator[](const int i) { if (i == 0) return mX; else if (i == 1) return mY; else if (i == 2) return mZ; else if (i == 3) return mW; else throw; }
		inline Vec4 operator-() const { return Vec4(-mX, -mY, -mZ, -mW); }

		friend std::ostream & operator<<(std::ostream & os, const Vec4 & v);

		/// Methods.
	public:
		Vec4 cross(const Vec4& other);
		F32 dot(const Vec4& other);
		F32 magnitude() const;
		F32 squaredMagnitude() const;
		F32 distance(const Vec4& other) const;
		F32 squaredDistance(const Vec4& other) const;

		inline Vec2 xy() { return Vec2(mX, mY); }
		inline Vec3 xyz() { return Vec3(mX, mY, mZ); }
	};

}

#endif
