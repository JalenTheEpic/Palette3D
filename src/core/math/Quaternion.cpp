#include <core\math\Quaternion.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Quaternion & v)
	{
		return os << "Quaternion(" << v.w << ", " << v.x << "," << v.y << "," << v.z << ")" << std::endl;
	}
}