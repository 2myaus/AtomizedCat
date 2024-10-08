#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

namespace AtomizedCat{
	struct scalar{
		// Single-dimension value
		private:
			double m;
		public:
			scalar operator+(const scalar &o) const;
			scalar operator-() const;
			scalar operator-(const scalar &o) const;
			scalar operator*(const scalar &o) const;
			scalar operator/(const scalar &o) const;
	};

	struct Vector3{
		scalar x;
		scalar y;
		scalar z;

		public:
			Vector3 operator+(const Vector3 &o) const;
			Vector3 operator-() const;
			Vector3 operator-(const Vector3 &o) const;

			scalar squaredMagnitude() const;
			scalar dot(const Vector3 &o) const;
			Vector3 cross(const Vector3 &o) const;
	};

	struct Position{
		Vector3 operator-(const Position &o) const;
		Position operator+(const Vector3 &o) const;
		private:
			Vector3 absolutepos; //Ranges from 0.0-1.0
	};
}

#endif
