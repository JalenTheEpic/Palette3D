#ifndef _CORE_MATH_QUATERNION_
#define _CORE_MATH_QUATERNION_
#include <core\math\Vec4.h>

namespace Palette3D
{
	class Quaternion
	{
		/// Member variables.
	private:
		Vec4 vec;

		/// Constructor and Destructor.
	public:
		inline Quaternion(const float w, const float x, const float y, const float z) : vec(Vec4(x, y, z, w)) {};
		~Quaternion() {}

		/// Operator functions.
	public:

		friend std::ostream & operator<<(std::ostream & os, const Vec4 & v);

		/// Methods.
	public:

	};
}

#endif