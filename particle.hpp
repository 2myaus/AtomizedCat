#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "primitives.hpp"

namespace AtomizedCat {
	struct Particle{
		Position position;
		scalar mass;

		Vector3 velocity;
	};
}

#endif
