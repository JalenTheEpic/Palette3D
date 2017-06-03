#include <core\math\Vec4.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Vec4 & v)
	{
		return os << "Vector4( " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << " )" << std::endl;
	}
	/*Vec4 Vec4::operator*(const Matrix4 & rhs) const
	{
		return Vec4(
			this->x * rhs[0][0] + this->y * rhs[0][1] + this->z * rhs[0][2] + this->w * rhs[0][3],
			this->x * rhs[1][0] + this->y * rhs[1][1] + this->z * rhs[1][2] + this->w * rhs[1][3],
			this->x * rhs[2][0] + this->y * rhs[2][1] + this->z * rhs[2][2] + this->w * rhs[2][3],
			this->x * rhs[3][0] + this->y * rhs[3][1] + this->z * rhs[3][2] + this->w * rhs[3][3]
		);
	}*/
	
	Vec4 Vec4::cross(const Vec4 & o) const
	{
		if (this->w != 0 || o.w != 0)
			//should we error here?
		return  Vec4(
			this->y*o.z - o.y*this->z,
			o.x*this->z - this->x*o.z,
			this->x*o.y - o.x*this->y,
			1.0f);
	}
	Vec4 Vec4::project(const Vec4 & other) const
	{
		Vec4 p;
		p =other * (this->dot(other) / other.squaredMagnitude());
		return p;
	}
	Vec4 Vec4::projectPerp(const Vec4 & other) const
	{
		return *this -  this->project(other);
	}
	F32 Vec4::dot(const Vec4 & other) const
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
	Vec4 Vec4::normalize() const
	{
		F32 mag = magnitude();
		return Vec4(x/mag,y/mag,z/mag);
	}
}