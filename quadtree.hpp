#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <memory>
#include <vector>
#include <array>
#include <optional>

#include "primitives.hpp"
#include "particle.hpp"

namespace AtomizedCat{
	struct Quad{
		// [ UL UR DL DR]
		const std::optional<std::array<std::shared_ptr<Quad>, 4>> Branches;

		const std::vector<std::shared_ptr<Particle>> Particles;
		const scalar mass; //Mass in grams

		Quad(
			const std::optional<std::array<std::shared_ptr<Quad>, 4>> &argBranches,
			const std::vector<std::shared_ptr<Particle>> &argParticles,
			const scalar &argMass
		);
	};

	std::unique_ptr<Quad> CalculateQuadTree(const std::vector<Particle> &Particles, const unsigned int maxDepth); // Create quadtree (setting mass) with the given points
	std::vector<Particle> CalculateParticlesStep(const Quad &ParticleTree /* Tree on which to calculate */, const scalar deltaTimeSeconds, const scalar gravitationConstant);
}

#endif
