#include <core\math\Quaternion.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Quaternion & v)
	{
		return os << "Quaternion(" << v.vec.mX << ", " << v.vec.mY << "," << v.vec.mZ << "," << v.vec.mW << ")" << std::endl;
	}
}