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
		float mX;
		float mY;
		float mZ;

		/// Constructor and Destructor.
	public:
		Vec3(const float x = 0.0f, const float y = 0.0f, const float z = 0.0f) :mX(x), mY(y) , mZ(z) {}
		Vec3(const Vec3& v):mX(v.mX), mY(v.mY), mZ(v.mZ) {}
		Vec3(const Vec2& v):mX(v.mX), mY(v.mY), mZ(0) {}
		~Vec3() {}

		/// Operator functions.
	public:
		inline Vec3 operator+(const Vec3& rhs);
		inline Vec3 operator-(const Vec3& rhs);
		inline Vec3 operator*(const float& rhs);

		inline void operator=(const Vec3& rhs);

		void operator+=(const Vec3& rhs) const;
		void operator-=(const Vec3& rhs) const;
		void operator*=(const float& rhs) const;

		friend std::ostream & operator<<(std::ostream & os, const Vec3 & v);

		/// Methods.
	public:
		Vec3 cross(const Vec3& other);
		float dot(const Vec3& other);
		float magnitude();

		
	};

}


#endif
