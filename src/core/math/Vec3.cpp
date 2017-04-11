#include <core\math\Vec3.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Vec3 & v)
	{
		return os << "Vector3(" << v.mX << ", " << v.mY <<"," << v.mZ << ")" << std::endl;
	}
	Vec3 Vec3::cross(const Vec3 & other)
	{
		return Vec3((mY*other.mZ - mZ*other.mY), (mZ*other.mX - mX*other.mZ), (mX*other.mY - mY*other.mX));
	}
	F32 Vec3::dot(const Vec3 & other)
	{
		return mX * other.mX + mY * other.mY + mZ * other.mZ;
	}
	F32 Vec3::magnitude() const
	{
		return static_cast<F32>(sqrt(mX*mX + mY*mY + mZ*mZ));
	}
	F32 Vec3::squaredMagnitude() const
	{
		return mX*mX + mY*mY + mZ*mZ;
	}
	F32 Vec3::distance(const Vec3 & other) const
	{
		return static_cast<F32>(sqrt(powf(other.mX - mX, 2) + powf(other.mY - mY, 2) + powf(other.mZ - mZ, 2)));
	}
	F32 Vec3::squaredDistance(const Vec3 & other) const
	{
		return static_cast<F32>(powf(other.mX - mX, 2) + powf(other.mY - mY, 2) + powf(other.mZ - mZ, 2));;
	}
}

