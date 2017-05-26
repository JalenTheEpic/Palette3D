/*
Palette3D
Copyright (c) 2017 Jalen Cureton
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_MATH_QUATERNION_
#define _CORE_MATH_QUATERNION_
#include <core\math\Vec4.h>

namespace Palette3D
{
	class Quaternion
	{
		/// Member variables.
	public:
		F32 w;
		F32 x;
		F32 y;
		F32 z;

		/// Constructor and Destructor.
	public:
		inline Quaternion(const F32 w, const F32 x, const F32 y, const F32 z) : w(w), x(x), y(y), z(z) {}
		inline Quaternion(const Vec4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
		inline Quaternion(const Vec3& v) : x(v.x), y(v.y), z(v.z), w(0) {}
		inline Quaternion(const Vec2& v) : x(v.x), y(v.y), z(0), w(0) {}
		~Quaternion() {}

		/// Operator functions.
	public:

		friend std::ostream & operator<<(std::ostream & os, const Quaternion & v);

		/// Methods.
	public:
	};
}

#endif