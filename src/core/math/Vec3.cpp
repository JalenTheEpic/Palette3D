#include <core\math\Vec3.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Vec3 & v)
	{
		return os << "Vector3(" << v.x << ", " << v.y <<"," << v.z << ")" << std::endl;
	}
	Vec3 Vec3::cross(const Vec3 & o)
	{
		return Vec3((this->y*o.z - this->z*o.y), 
			(this->z*o.x - this->x*o.z), 
			(this->x*o.y - this->y*o.x));
	}
	F32 Vec3::dot(const Vec3 & o)
	{
		return this->x * o.x + this->y * o.y + this->z * o.z;
	}
	F32 Vec3::magnitude() const
	{
		return static_cast<F32>(sqrt(this->x*this->x + this->y*this->y + this->z*this->z));
	}
	F32 Vec3::squaredMagnitude() const
	{
		return this->x*this->x + this->y*this->y + this->z*this->z;
	}
	F32 Vec3::distance(const Vec3 & o) const
	{
		return static_cast<F32>(sqrt(powf(o.x - this->x, 2) + powf(o.y - this->y, 2) + powf(o.z - this->z, 2)));
	}
	F32 Vec3::squaredDistance(const Vec3 & o) const
	{
		return static_cast<F32>(powf(o.x - this->x, 2) + powf(o.y - this->y, 2) + powf(o.z - this->z, 2));;
	}
	Vec3 Vec3::normalize() const
	{
		F32 mag = this->magnitude();
		return Vec3(this->x/mag, this->y/mag, this->z/mag);
	}
}

