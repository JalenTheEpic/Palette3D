#include <core\math\Vec4.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Vec4 & v)
	{
		return os << "Vector4(" << v.x << ", " << v.y << "," << v.z << "," << v.w << ")" << std::endl;
	}
	Vec4 Vec4::cross(const Vec4 & other)
	{
		return Vec4();
	}
	F32 Vec4::dot(const Vec4 & other)
	{
		return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
	}
	F32 Vec4::magnitude() const
	{
		return static_cast<F32>(sqrt(this->x*this->x + this->y*this->y + this->z*this->z + this->w*this->w));
	}
	F32 Vec4::squaredMagnitude() const
	{
		return this->x*this->x + this->y*this->y + this->z*this->z + this->w*this->w;
	}
	F32 Vec4::distance(const Vec4 & other) const
	{
		return static_cast<F32>(sqrt(powf(other.x - this->x, 2) + powf(other.y - this->y, 2) + powf(other.z - this->z, 2) + powf(other.w - this->w, 2)));
	}
	F32 Vec4::squaredDistance(const Vec4 & other) const
	{
		return static_cast<F32>(powf(other.x - this->x, 2) + powf(other.y - this->y, 2) + powf(other.z - this->z, 2) + powf(other.w - this->w, 2));;
	}
}