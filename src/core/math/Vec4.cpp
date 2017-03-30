#include <core\math\Vec4.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Vec4 & v)
	{
		return os << "Vector4(" << v.mX << ", " << v.mY << "," << v.mZ << "," << v.mW << ")" << std::endl;
	}
	Vec3 Vec4::cross(const Vec4 & other)
	{
		return Vec3();
	}
	float Vec4::dot(const Vec4 & other)
	{
		return mX * other.mX + mY * other.mY + mZ * other.mZ + mW * other.mW;
	}
	float Vec4::magnitude() const
	{
		return static_cast<float>(sqrt(mX*mX + mY*mY + mZ*mZ + mW*mW));
	}
	float Vec4::squaredMagnitude() const
	{
		return mX*mX + mY*mY + mZ*mZ + mW*mW;
	}
	float Vec4::distance(const Vec4 & other) const
	{
		return static_cast<float>(sqrt(powf(other.mX - mX, 2) + powf(other.mY - mY, 2) + powf(other.mZ - mZ, 2) + powf(other.mW - mW, 2)));
	}
	float Vec4::squaredDistance(const Vec4 & other) const
	{
		return static_cast<float>(powf(other.mX - mX, 2) + powf(other.mY - mY, 2) + powf(other.mZ - mZ, 2) + powf(other.mW - mW, 2));;
	}
}