#pragma once

#include "cinder/gl/gl.h"
#include "particle.h"

namespace idealgas {

/**
 * The container in which all of the gas particles are contained. This class
 * stores all of the particles and updates them on each frame of the simulation.
 */
class GasContainer {
 public:
  /**
   * Constructor initializes a vector of Particle objects.
   * @param particles
   */
  GasContainer(std::vector<Particle> particles);

  /**
   * Displays the container walls and the current positions of the particles.
   */
  void Display() const;

  /**
   * Updates the positions and velocities of all particles (based on the rules
   * described in the assignment documentation).
   */
  void AdvanceOneFrame();

  std::vector<Particle> const &get_particles();

  void set_particles(std::vector<Particle> particles);

  static const glm::vec2 &getKFirstCorner();
  static const glm::vec2 &getKSecondCorner();

 private:
  /**
   * The vector of Particle objects in the container.
   */
  std::vector<Particle> particles_;
};
/**
 * The first corner of the rectangular container.
 * Currently a constant, can be changed if container adjustment is
 * implemented.
 */
static const glm::vec2 kFirstCorner{100, 100};

/**
 * The opposite corner of the rectangular container.
 * Currently a constant, can be changed if container adjustment is
 * implemented.
 */
static const glm::vec2 kSecondCorner{600, 400};
}  // namespace idealgas
