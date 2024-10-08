#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <memory>
#include <vector>
#include <optional>

#include "primitives.hpp"
#include "particle.hpp"

namespace AtomizedCat{
	struct Quad{
		// [ UL UR ]
		// [ DL DR ]
		std::optional<std::unique_ptr<Quad>> *UL;
		std::optional<std::unique_ptr<Quad>> *UR;
		std::optional<std::unique_ptr<Quad>> *DL;
		std::optional<std::unique_ptr<Quad>> *DR;

		std::optional<std::vector<Particle*>> Particles;
		scalar mass; //Mass in grams
	};

	std::unique_ptr<Quad> CalculateQuadTree(const std::vector<Particle> &Particles, const unsigned int maxDepth); // Create quadtree (setting mass) with the given points
	std::vector<Particle> CalculateParticlesStep(const Quad &ParticleTree /* Tree on which to calculate */, const scalar deltaTimeSeconds, const scalar gravitationConstant);
}

#endif
