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
		// [ -Y,-X / -Y,X / Y,-X / Y,X ]
		const std::optional<const std::array<const std::shared_ptr<const Quad>, 4>> Branches;

		const std::vector<std::shared_ptr<const Particle>> Particles;
		const scalar mass; //Mass in grams

		Quad(
			const std::optional<const std::array<const std::shared_ptr<const Quad>, 4>> &argBranches,
			const std::vector<std::shared_ptr<const Particle>> &argParticles,
			const scalar argMass
		);

		Quad(const std::vector<std::shared_ptr<const Particle>> &argParticles, const scalar argMass);

		Quad();
	};

	std::unique_ptr<Quad> CalculateQuadTree(const std::vector<const Particle> &Particles, const unsigned int maxDepth, const Vector3 bounds /* x,y = lowest x/y, z = side length, valid on [x,x+z) */); // Create quadtree (setting mass) with the given points
	std::vector<Particle> CalculateParticlesStep(const Quad &ParticleTree /* Tree on which to calculate */, const scalar deltaTimeSeconds, const scalar gravitationConstant);
}

#endif
