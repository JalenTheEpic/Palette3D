#include "core\math\Vec2.h"
#include <math.h>

namespace Palette3D
{
	

	Vec2::~Vec2()
	{

	}


	Vec2 Vec2::operator+(const Vec2& rhs) const
	{
		return Vec2(mX + rhs.mX, mY + rhs.mY);
	}


	Vec2 Vec2::operator-(const Vec2& rhs) const
	{
		return Vec2(mX - rhs.mX, mY - rhs.mY);
	}


	Vec2 Vec2::operator*(const float& rhs) const
	{
		return Vec2(mX * rhs, mY * rhs);

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
		return static_cast<float>(sqrt(powf(mX, 2) + powf(mY, 2)));
	}
}