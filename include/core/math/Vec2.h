#ifndef _CORE_MATH_VEC2_
#define _CORE_MATH_VEC2_

namespace Palette3D 
{
	class Vec2
	{
		/// Member variables.
	public:
		float mX;
		float mY;

		/// Constructor and Destructor.
	public:
		Vec2(const float x = 0.0f, const float y = 0.0f);
		~Vec2();

		/// Operator functions.
	public:
		Vec2 operator+(const Vec2& rhs);
		Vec2 operator-(const Vec2& rhs);
		Vec2 operator*(const float& rhs);

		/// Methods.
	public:
		Vec2 cross(const Vec2& other);
		float dot(const Vec2& other);
		float magnitude();
	};

}


#endif
