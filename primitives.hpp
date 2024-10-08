#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

namespace AtomizedCat{
	struct scalar{
		// Single-dimension value
		double m;
	};

	scalar operator+(const scalar &left, const scalar &right);
	scalar operator-(const scalar &left, const scalar &right);

	struct Vector3{
		scalar x;
		scalar y;
		scalar z;
	};
	
	Vector3 operator+(const Vector3 &left, const Vector3 &right);
	Vector3 operator-(const Vector3 &left, const Vector3 &right);
	Vector3 operator-(const Vector3 &vec);

	scalar magnitude(const Vector3 vec);
	scalar dot(const Vector3 left, const Vector3 right);
	scalar cross(const Vector3 left, const Vector3 right);

	struct Position{
		private:
			Vector3 absolutepos; //Ranges from 0.0-1.0
	};

	Vector3 operator-(const Position &left, const Position &right);
	Position operator+(const Position &left, const Vector3 &right);
	Position operator+(const Vector3 &left, const Position &right);
}

#endif
