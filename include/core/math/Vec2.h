/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_MATH_VEC2_
#define _CORE_MATH_VEC2_

#include <iostream>
#include "core/atomic/Types.h"

namespace Palette3D 
{
	class Vec2
	{
		/// Member variables.
	public:
		F32 x;
		F32 y;
		
		/// Constructor and Destructor.
	public:
		inline Vec2(const F32 x = 0.0f, const F32 y = 0.0f) : x(x), y(y) {}
		inline Vec2(const Vec2& rhs):x(rhs.x), y(rhs.y) {}
		inline ~Vec2() {}

		/// Operator functions.
	public:
		inline Vec2 operator+(const Vec2& rhs) const { return Vec2(this->x + rhs.x, this->y + rhs.y); }
		inline Vec2 operator-(const Vec2& rhs) const { return Vec2(this->x - rhs.x, this->y -  rhs.y); }
		inline Vec2 operator*(const F32& rhs) const { return Vec2(this->x * rhs, this->y * rhs); }

		inline void operator=(const Vec2& rhs) { this->x = rhs.x; this->y = rhs.y; }

		inline void operator+=(const Vec2& rhs) { this->x += rhs.x; this->y += rhs.y; }
		inline void operator-=(const Vec2& rhs) { this->x -= rhs.x; this->y -= rhs.y; }
		inline void operator*=(const F32& rhs) { this->x *= rhs; this->y *= rhs; }

		inline F32 operator[](const int i) const { if (i == 0) return this->x; else if (i == 1) return this->y; else throw; }
		inline Vec2 operator-() const { return Vec2(-this->x, -this->y); }

		friend std::ostream& operator<< (std::ostream& os, const Vec2& v);

		/// Methods.
	public:
		Vec2 cross(const Vec2& other) const;
		F32 dot(const Vec2& other) const;
		F32 magnitude() const;
		F32 squaredMagnitude() const;
		F32 distance(const Vec2& other) const;
		F32 squaredDistance(const Vec2& other) const;
	};
}

#endif
