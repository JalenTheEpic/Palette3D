/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_MATH_VEC3_
#define _CORE_MATH_VEC3_
#include <core\math\Vec2.h>
namespace Palette3D 
{
	class Vec3
	{
		/// Member variables.
	public:
		F32 mX;
		F32 mY;
		F32 mZ;

		/// Constructor and Destructor.
	public:
		inline Vec3(const F32 x = 0.0f, const F32 y = 0.0f, const F32 z = 0.0f) : mX(x), mY(y) , mZ(z) {}
		inline Vec3(const Vec3& v):mX(v.mX), mY(v.mY), mZ(v.mZ) {}
		inline Vec3(const Vec2& v):mX(v.mX), mY(v.mY), mZ(0) {}
		inline ~Vec3() {}

		/// Operator functions.
	public:
		inline Vec3 operator+(const Vec3& rhs) const { return Vec3(mX + rhs.mX, mY + rhs.mY, mZ + rhs.mZ); }
		inline Vec3 operator-(const Vec3& rhs) const { return Vec3(mX - rhs.mX, mY - rhs.mY, mZ - rhs.mZ); }
		inline Vec3 operator*(const F32& rhs) const { return Vec3(mX * rhs, mY * rhs, mZ * rhs); }

		inline void operator=(const Vec3& rhs) { mX = rhs.mX; mY = rhs.mY; mZ = rhs.mZ; }

		inline void operator+=(const Vec3& rhs) { mX += rhs.mX; mY += rhs.mY; mZ += rhs.mZ; }
		inline void operator-=(const Vec3& rhs) { mX -= rhs.mX; mY -= rhs.mY; mZ -= rhs.mZ; }
		inline void operator*=(const F32& rhs) { mX *= rhs; mY *= rhs; mZ *= rhs; }

		inline F32 operator[](const int i) { if (i == 0) return mX; else if (i == 1) return mY; else if (i == 2) return mZ; else throw; }
		inline Vec3 operator-() const { return Vec3(-mX, -mY, -mZ); }

		friend std::ostream & operator<<(std::ostream & os, const Vec3 & v);

		/// Methods.
	public:
		Vec3 cross(const Vec3& other);
		F32 dot(const Vec3& other);
		F32 magnitude() const;
		F32 squaredMagnitude() const;
		F32 distance(const Vec3& other) const;
		F32 squaredDistance(const Vec3& other) const;

		inline Vec2 xy() { return Vec2(mX, mY); }
	};

}


#endif
