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
	class Vec2;
	class Vec3;

	class Vec4
	{
		/// Member variables.
	public:
		float mX;
		float mY;
		float mZ;
		float mW;

		/// Constructor and Destructor.
	public:
		inline Vec4(const float x = 0.0f, const float y = 0.0f, const float z = 0.0f, const float w = 0.0f) :mX(x), mY(y), mZ(z), mW(w) {}
		inline Vec4(const Vec4& v) : mX(v.mX), mY(v.mY), mZ(v.mZ), mW(v.mW) {}
		inline Vec4(const Vec3& v) : mX(v.mX), mY(v.mY), mZ(v.mZ), mW(0) {}
		inline Vec4(const Vec2& v) : mX(v.mX), mY(v.mY), mZ(0), mW(0) {}
		~Vec4() {}

		/// Operator functions.
	public:
		inline Vec4 operator+(const Vec4& rhs) const { return Vec4(mX + rhs.mX, mY + rhs.mY, mZ + rhs.mZ, mW + rhs.mW); }
		inline Vec4 operator-(const Vec4& rhs) const { return Vec4(mX - rhs.mX, mY - rhs.mY, mZ - rhs.mZ, mW - rhs.mW); }
		inline Vec4 operator*(const float& rhs) const { return Vec4(mX * rhs, mY * rhs, mZ * rhs, mW * rhs); }

		inline void operator=(const Vec4& rhs) { mX = rhs.mX; mY = rhs.mY; mZ = rhs.mZ; mW = rhs.mW; }

		void operator+=(const Vec4& rhs) { mX += rhs.mX; mY += rhs.mY; mZ += rhs.mZ; mW += rhs.mW; }
		void operator-=(const Vec4& rhs) { mX -= rhs.mX; mY -= rhs.mY; mZ -= rhs.mZ; mW -= rhs.mW; }
		void operator*=(const float& rhs) { mX *= rhs; mY *= rhs; mZ *= rhs; mW *= rhs; }

		friend std::ostream & operator<<(std::ostream & os, const Vec4 & v);

		/// Methods.
	public:
		Vec3 cross(const Vec4& other);
		float dot(const Vec4& other);
		float magnitude() const;
		float squaredMagnitude() const;
		float distance(const Vec4& other) const;
		float squaredDistance(const Vec4& other) const;


		friend Vec2;
		friend Vec3;
	};

}

#endif
