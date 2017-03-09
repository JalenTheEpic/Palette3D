#include <core\math\Vec3.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Vec3 & v)
	{
		return os << "Vector3(" << v.mX << ", " << v.mY <<"," << v.mZ << ")" << std::endl;
	}
}

