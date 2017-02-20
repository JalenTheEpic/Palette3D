#ifndef _CORE_MATH_VEC3_
#define _CORE_MATH_VEC3_

namespace Palette3D 
{
	class Vec3
	{
		/// Member variables.
	public:
		float mX;
		float mY;
		float mZ;

		/// Constructor and Destructor.
	public:
		Vec3(const float x = 0.0f, const float y = 0.0f, const float z = 0.0f) :mX(x), mY(y) , mZ(z) {}
		~Vec3() {}

		/// Operator functions.
	public:
		Vec3 operator+(const Vec3& rhs);
		Vec3 operator-(const Vec3& rhs);
		Vec3 operator*(const float& rhs);

		/// Methods.
	public:
		Vec3 cross(const Vec3& other);
		float dot(const Vec3& other);
		float magnitude();
	};

}


#endif
