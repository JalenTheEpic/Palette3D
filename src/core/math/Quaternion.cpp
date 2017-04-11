#include <core\math\Quaternion.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Vec4 & v)
	{
		return os << "Quaternion(" << v.mW << "," << v.mX << ", " << v.mY << "," << v.mZ << ")" << std::endl;
	}
}