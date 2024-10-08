#include "quadtree.hpp"

#include <optional>

namespace AtomizedCat {

	Quad::Quad(
		const std::optional<std::array<std::shared_ptr<Quad>,4>> &argBranches,
		const std::vector<std::shared_ptr<Particle>> &argParticles,
		const scalar &argMass):mass(argMass),Particles(argParticles),Branches(argBranches){}
}
