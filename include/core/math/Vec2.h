/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_MATH_VEC2_
#define _CORE_MATH_VEC2_

#include <iostream>

namespace Palette3D 
{
	class Vec3;


	class Vec2
	{
		/// Member variables.
	public:
		float mX;
		float mY;
		
		/// Constructor and Destructor.
	public:
		inline Vec2(const float x = 0.0f, const float y = 0.0f):mX(x), mY(y) {}
		inline Vec2(const Vec2& rhs):mX(rhs.mX), mY(rhs.mY) {}


		~Vec2();

		/// Operator functions.
	public:
		inline Vec2 operator+(const Vec2& rhs) const
		{
			return Vec2(mX + rhs.mX, mY + rhs.mY);
		}
		
		inline Vec2 operator-(const Vec2& rhs) const
		{
			return Vec2(mX - rhs.mX, mY -  rhs.mY);
		}
		Vec2 operator*(const float& rhs) const
		{
			return Vec2(mX * rhs, mY * rhs);
		}

		void operator+=(const Vec2& rhs);
		void operator-=(const Vec2& rhs);
		void operator*=(const float& rhs);

		inline void operator=(const Vec2& rhs) 
		{
			mX = rhs.mX;
			mX = rhs.mY;
		}
		friend std::ostream& operator<< (std::ostream& os, const Vec2& v);
		/// Methods.
	public:
		Vec2 cross(const Vec2& other) const;
		float dot(const Vec2& other) const;
		float magnitude() const;
		float squaredMagnitude() const;
		float distance(const Vec2& other) const;
		float squaredDistance(const Vec2& other) const;

		friend Vec3;
	};

}


#endif
