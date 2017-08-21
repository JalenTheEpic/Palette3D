#include "core\math\Vec2.h"
#include <math.h>

namespace Palette3D {
	std::ostream & operator<<(std::ostream & os, const Vec2 & v) {
		return os << "Vector2(" << v.x << ", " << v.y << ")" << std::endl;
	}
	Vec2 Vec2::cross(const Vec2 & other) const {
		return Vec2(this->x * other.y, this->y * other.x);
	}

	F32 Vec2::dot(const Vec2 & other) const {
		return this->x * other.x + this->y * other.y;
	}

	F32 Vec2::magnitude() const {
		return static_cast<F32>(sqrt(this->x*this->x + this->y*this->y));
	}
	F32 Vec2::squaredMagnitude() const {
		return this->x*this->x + this->y*this->y;
	}
	F32 Vec2::distance(const Vec2 & other) const {
		return static_cast<F32>(sqrt(powf(other.x - this->x, 2) + powf(other.y - this->y, 2)));
	}
	F32 Vec2::squaredDistance(const Vec2& other) const {
		return static_cast<F32>(powf(other.x - this->x, 2) + powf(other.y - this->y, 2));;
	}
	Vec2 Vec2::normalize() const {
		F32 mag = this->magnitude();
		return Vec2(this->x/mag, this->y/mag);
	}
}