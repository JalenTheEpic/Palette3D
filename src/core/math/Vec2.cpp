#include "core\math\Vec2.h"
#include <math.h>

namespace Palette3D
{
	std::ostream & operator<<(std::ostream & os, const Vec2 & v)
	{
		return os << "Vector2(" << v.mX << ", " << v.mY << ")" << std::endl;
	}
	Vec2 Vec2::cross(const Vec2 & other) const
	{
		return Vec2(mX * other.mY, mY * other.mX);
	}

	F32 Vec2::dot(const Vec2 & other) const
	{
		return mX * other.mX + mY * other.mY;
	}

	F32 Vec2::magnitude() const
	{
		return static_cast<F32>(sqrt(mX*mX + mY*mY));
	}
	F32 Vec2::squaredMagnitude() const
	{
		return mX*mX + mY*mY;
	}
	F32 Vec2::distance(const Vec2 & other) const
	{
		return static_cast<F32>(sqrt(powf(other.mX - mX, 2) + powf(other.mY - mY, 2)));
	}
	F32 Vec2::squaredDistance(const Vec2& other) const
	{
		return static_cast<F32>(powf(other.mX - mX, 2) + powf(other.mY - mY, 2));;
	}
}