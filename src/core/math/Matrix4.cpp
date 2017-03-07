#include <core\math\Matrix4.h>
namespace Palette3D 
{
	const Matrix4 Matrix4::IDENTITY(1.f, 0.f, 0.f,0.f,
									0.f, 1.f, 0.f,0.f,
									0.f, 0.f, 1.f,0.f,
									0.f, 0.f, 0.f, 1.f);

	const Matrix4 Matrix4::ZERO(0.f, 0.f, 0.f, 0.f,
								0.f, 0.f, 0.f, 0.f,
								0.f, 0.f, 0.f, 0.f,
								0.f, 0.f, 0.f, 0.f);

	Matrix4 Matrix4::operator+(const Matrix4 & other) const
	{
		return Matrix4();
	}
	void Matrix4::operator+=(const Matrix4 & other)
	{
	}
	Matrix4 Matrix4::operator-(const Matrix4 & other) const
	{
		return Matrix4();
	}
	void Matrix4::operator-=(const Matrix4 & other)
	{
	}
	Matrix4 Matrix4::operator*(float scalar) const
	{
		return Matrix4();
	}
	void Matrix4::operator*=(float scalar)
	{
	}
	Matrix4 Matrix4::operator*(const Matrix4 & other) const
	{
		return Matrix4();
	}
	void Matrix4::operator*=(const Matrix4 & other)
	{
	}
	Matrix4 Matrix4::operator-() const
	{
		return Matrix4();
	}
	Vec4 Matrix4::operator*(const Vec4 & other) const
	{
		return Vec4();
	}
	bool Matrix4::operator!=(const Matrix4 & other) const
	{
		return false;
	}
	bool Matrix4::operator==(const Matrix4 & other) const
	{
		return false;
	}
	Matrix4 Matrix4::transpose() const
	{
		return Matrix4();
	}
	float Matrix4::determinant() const
	{
		return 0.0f;
	}
	Vec4 Matrix4::getRow(std::size_t row) const
	{
		return Vec4();
	}
	void Matrix4::setRow(std::size_t row, Vec4 v)
	{
	}
	
	Vec4 Matrix4::getCol(std::size_t col) const
	{
		return Vec4();
	}
	void Matrix4::setCol(std::size_t col, Vec4 v)
	{
	}
	std::ostream & operator<<(std::ostream & os, const Matrix4 & m)
	{
		return os;
	}
}
