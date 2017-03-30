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

	float Vec2::dot(const Vec2 & other) const
	{
		return mX * other.mX + mY * other.mY;
	}

	float Vec2::magnitude() const
	{
		return static_cast<float>(sqrt(mX*mX + mY*mY));
	}
	float Vec2::squaredMagnitude() const
	{
		return mX*mX + mY*mY;
	}
	float Vec2::distance(const Vec2 & other) const
	{
		return static_cast<float>(sqrt(powf(other.mX - mX, 2) + powf(other.mY - mY, 2)));
	}
	float Vec2::squaredDistance(const Vec2& other) const
	{
		return static_cast<float>(powf(other.mX - mX, 2) + powf(other.mY - mY, 2));;
	}
}