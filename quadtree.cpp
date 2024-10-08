#include "quadtree.hpp"

#include <optional>
#include <algorithm>
#include <cmath>

namespace AtomizedCat {

	Quad::Quad(
		const std::optional<const std::array<const std::shared_ptr<const Quad>,4>> &argBranches,
		const std::vector<std::shared_ptr<const Particle>> &argParticles,
		const scalar argMass):mass(argMass),Particles(argParticles),Branches(argBranches){}

	Quad::Quad(const std::vector<std::shared_ptr<const Particle>> &argParticles, const scalar argMass):
		mass(argMass),Particles(argParticles){}

	Quad::Quad():mass(0),Particles(){}

	std::unique_ptr<Quad> CalculateQuadTree(const std::vector<std::shared_ptr<Particle>> &Particles, const unsigned int maxDepth, const Vector3 bounds){

		//First, separate the points along a grid
		std::vector<std::shared_ptr<const Particle>> particleGrid[maxDepth][maxDepth];

		std::for_each(Particles.begin(), Particles.end(), [&](const std::shared_ptr<const Particle> valParticle) {
			unsigned int cellX = floor((valParticle->position.absolutepos.x - bounds.x) / bounds.z);
			unsigned int cellY = floor((valParticle->position.absolutepos.y - bounds.y) / bounds.z);

			particleGrid[cellY][cellX].push_back(valParticle);
		});

		//TODO: Transform grid into quadtree

		
	}
}
