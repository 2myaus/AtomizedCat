#include "primitives.hpp"

namespace AtomizedCat {
	scalar scalar::operator+(const scalar& o) const{
		return scalar(o.m + m);
	}

	scalar scalar::operator-() const{
		return scalar(-m);
	}

	scalar scalar::operator-(const scalar &o) const{
		return *this + (-o);
	}

	scalar scalar::operator*(const scalar &o) const{
		return scalar(m * o.m);
	}

	scalar scalar::operator/(const scalar &o) const{
		return scalar(m / o.m);
	}

	scalar::scalar(const double magnitude): m(magnitude){};
	scalar::scalar(const scalar &rhs): scalar(rhs.m){};

	Vector3 Vector3::operator+(const Vector3 &o) const{
		return Vector3(x+o.x,y+o.y,z+o.z);
	}

	Vector3 Vector3::operator-() const{
		return Vector3(-x,-y,-z);
	}

	Vector3 Vector3::operator-(const Vector3 &o) const{
		return *this + (-o);
	}

	Vector3::Vector3(const scalar argX, const scalar argY, const scalar argZ):
		x(argX),y(argY),z(argZ){};

	Vector3::Vector3(const Vector3 &rhs):
		Vector3(rhs.x,rhs.y,rhs.z){};

	scalar Vector3::squaredMagnitude() const{
		return x*x+y*y+z*z;
	}

	scalar Vector3::dot(const Vector3 &o) const{
		return o.x*x+o.y*y+o.z*z;
	}

	Vector3 Vector3::cross(const Vector3 &o) const{
		return Vector3(
			y*o.z-z*o.y,
			z*o.x-x*o.z,
			x*o.y-y*o.x
			);
	}

	Vector3 Position::operator-(const Position &o) const{
		return absolutepos-o.absolutepos;
	}

	Position Position::operator+(const Vector3 &o) const{
		Position n = *this;
		n.absolutepos = n.absolutepos + o;
		
		return n;
	}

	Position::Position(const Position &ref, const Vector3 &dif):
		absolutepos(ref.absolutepos + dif){};

	Position::Position(const Position &rhs):
		absolutepos(rhs.absolutepos){};
}
