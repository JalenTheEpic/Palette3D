#include <core\math\Vec3.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Vec3 & v)
	{
		return os << "Vector3(" << v.x << ", " << v.y <<"," << v.z << ")" << std::endl;
	}
	Vec3 Vec3::cross(const Vec3 & other)
	{
		return Vec3((this->y*other.z - this->z*other.y), (this->z*other.x - this->x*other.z), (this->x*other.y - this->y*other.x));
	}
	F32 Vec3::dot(const Vec3 & other)
	{
		return this->x * other.x + this->y * other.y + this->z * other.z;
	}
	F32 Vec3::magnitude() const
	{
		return static_cast<F32>(sqrt(this->x*this->x + this->y*this->y + this->z*this->z));
	}
	F32 Vec3::squaredMagnitude() const
	{
		return this->x*this->x + this->y*this->y + this->z*this->z;
	}
	F32 Vec3::distance(const Vec3 & other) const
	{
		return static_cast<F32>(sqrt(powf(other.x - this->x, 2) + powf(other.y - this->y, 2) + powf(other.z - this->z, 2)));
	}
	F32 Vec3::squaredDistance(const Vec3 & other) const
	{
		return static_cast<F32>(powf(other.x - this->x, 2) + powf(other.y - this->y, 2) + powf(other.z - this->z, 2));;
	}
}

