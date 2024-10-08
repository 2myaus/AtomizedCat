#include "primitives.hpp"

namespace AtomizedCat {
	scalar scalar::operator+(const scalar& o) const{
		scalar n;
		n.m = o.m + m;

		return n;
	}

	scalar scalar::operator-() const{
		scalar n;
		n.m = -m;
		
		return n;
	}

	scalar scalar::operator-(const scalar &o) const{
		return *this + (-o);
	}

	scalar scalar::operator*(const scalar &o) const{
		scalar n;
		n.m = m * (o.m);
		return n;
	}

	scalar scalar::operator/(const scalar &o) const{
		scalar n;
		n.m = m / (o.m);
		return n;
	}

	Vector3 Vector3::operator+(const Vector3 &o) const{
		Vector3 n;
		n.x = x + o.x;
		n.y = y + o.y;
		n.z = z + o.z;

		return n;
	}

	Vector3 Vector3::operator-() const{
		Vector3 n;
		n.x = -x;
		n.y = -y;
		n.z = -z;
		
		return n;
	}

	Vector3 Vector3::operator-(const Vector3 &o) const{
		return *this + (-o);
	}

	scalar Vector3::squaredMagnitude() const{
		return x*x+y*y+z*z;
	}

	scalar Vector3::dot(const Vector3 &o) const{
		return o.x*x+o.y*y+o.z*z;
	}

	Vector3 Vector3::cross(const Vector3 &o) const{
		Vector3 n;

		n.x = y*o.z-z*o.y;
		n.y = z*o.x-x*o.z;
		n.z = x*o.y-y*o.x;

		return n;
	}

	Vector3 Position::operator-(const Position &o) const{
		return absolutepos-o.absolutepos;
	}

	Position Position::operator+(const Vector3 &o) const{
		Position n = *this;
		n.absolutepos = n.absolutepos + o;
		
		return n;
	}
}
