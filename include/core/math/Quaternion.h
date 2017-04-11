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
		inline Quaternion(const F32 w, const F32 x, const F32 y, const F32 z) : vec(Vec4(x, y, z, w)) {};
		~Quaternion() {}

		/// Operator functions.
	public:

		friend std::ostream & operator<<(std::ostream & os, const Quaternion & v);

		/// Methods.
	public:

	};
}

#endif