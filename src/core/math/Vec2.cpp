#include "core\math\Vec2.h"
#include <math.h>


Palette3D::Vec2::Vec2(const float x, const float y) : mX(x), mY(y)
{

}

Palette3D::Vec2::~Vec2()
{
	
}


Palette3D::Vec2 Palette3D::Vec2::operator+(const Vec2& rhs)
{
	return Vec2(mX + rhs.mX, mY + rhs.mY);
}


Palette3D::Vec2 Palette3D::Vec2::operator-(const Vec2& rhs)
{
	return Vec2( mX - rhs.mX, mY - rhs.mY);
}


Palette3D::Vec2 Palette3D::Vec2::operator*(const float& rhs)
{
	return Vec2(mX * rhs, mY * rhs);

}

Palette3D::Vec2 Palette3D::Vec2::cross(const Vec2 & other)
{
	return Vec2(mX * other.mY, mY * other.mX);
}

float Palette3D::Vec2::dot(const Vec2 & other)
{
	return mX * other.mX + mY * other.mY;
}

float Palette3D::Vec2::magnitude()
{
	return static_cast<float>(sqrt(powf(mX, 2) + powf(mY, 2)));
}
