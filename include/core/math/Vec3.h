/*
Palette3D
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
		F32 x;
		F32 y;
		F32 z;

		/// Constructor and Destructor.
	public:
		inline Vec3(const F32 x = 0.0f, const F32 y = 0.0f, const F32 z = 0.0f) : x(x), y(y) , z(z) {}
		inline Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
		inline Vec3(const Vec2& v) : x(v.x), y(v.y), z(0) {}
		inline ~Vec3() {}

		/// Operator functions.
	public:
		inline Vec3 operator+(const Vec3& rhs) const { return Vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z); }
		inline Vec3 operator-(const Vec3& rhs) const { return Vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z); }
		inline Vec3 operator*(const F32& rhs) const { return Vec3(this->x * rhs, this->y * rhs, this->z * rhs); }

		inline void operator=(const Vec3& rhs) { this->x = rhs.x; this->y = rhs.y; this->z = rhs.z; }

		inline void operator+=(const Vec3& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; }
		inline void operator-=(const Vec3& rhs) { this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; }
		inline void operator*=(const F32& rhs) { this->x *= rhs; this->y *= rhs; this->z *= rhs; }

		inline F32 operator[](const int i) { if (i == 0) return this->x; else if (i == 1) return this->y; else if (i == 2) return this->z; else throw; }
		inline Vec3 operator-() const { return Vec3(-this->x, -this->y, -this->z); }

		friend std::ostream & operator<<(std::ostream & os, const Vec3 & v);

		/// Methods.
	public:
		Vec3 cross(const Vec3& other);
		F32 dot(const Vec3& other);
		F32 magnitude() const;
		F32 squaredMagnitude() const;
		F32 distance(const Vec3& other) const;
		F32 squaredDistance(const Vec3& other) const;

		inline Vec2 xy() { return Vec2(this->x, this->y); }
	};

}


#endif
