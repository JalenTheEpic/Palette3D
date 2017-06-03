/*
Palette3D
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
		F32 x;
		F32 y;
		F32 z;
		F32 w;

		/// Constructor and Destructor.
	public:
		inline Vec4(const F32 x = 0.0f, const F32 y = 0.0f, const F32 z = 0.0f, const F32 w = 0.0f) : x(x), y(y), z(z), w(w) {}
		inline Vec4(const Vec4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
		inline Vec4(const Vec3& v) : x(v.x), y(v.y), z(v.z), w(1) {}
		inline Vec4(const Vec2& v) : x(v.x), y(v.y), z(0), w(1) {}
		~Vec4() {}

		/// Operator functions.
	public:
		inline Vec4 operator+(const Vec4& rhs) const { return Vec4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w); }
		inline Vec4 operator-(const Vec4& rhs) const { return Vec4(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w); }
		inline Vec4 operator*(const F32& rhs) const { return Vec4(this->x * rhs, this->y * rhs, this->z * rhs, this->w * rhs); }

		inline void operator=(const Vec4& rhs) { this->x = rhs.x; this->y = rhs.y; this->z = rhs.z; this->w = rhs.w; }

		inline void operator+=(const Vec4& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; this->w += rhs.w; }
		inline void operator-=(const Vec4& rhs) { this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; this->w -= rhs.w; }
		inline void operator*=(const F32& rhs) { this->x *= rhs; this->y *= rhs; this->z *= rhs; this->w *= rhs; }

		inline F32 operator[](const int i) { if (i == 0) return this->x; else if (i == 1) return this->y; else if (i == 2) return this->z; else if (i == 3) return this->w; else throw; }
		inline Vec4 operator-() const { return Vec4(-this->x, -this->y, -this->z, -this->w); }

		friend std::ostream & operator<<(std::ostream & os, const Vec4 & v);

		/// Methods.
	public:
		Vec4 cross(const Vec4& other) const;

		///Project this vector on to the other
		Vec4 project(const Vec4& other)const;

		///Gets the perpendicular component of this with respect to other
		Vec4 projectPerp(const Vec4& other)const;



		F32 dot(const Vec4& other) const;
		F32 magnitude() const;
		F32 squaredMagnitude() const;
		F32 distance(const Vec4& other) const;
		F32 squaredDistance(const Vec4& other) const;
		Vec4 normalize() const;
		inline Vec2 xy() { return Vec2(this->x, this->y); }
		inline Vec3 xyz() { return Vec3(this->x, this->y, this->z); }
	};

}

#endif
