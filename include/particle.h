#pragma once
#include "cinder/gl/gl.h"

class Particle {
 public:
  /**
   * Constructor sets 2d vector values for the position and velocity of the
   * particle and a float for the radius of the particle
   */
  Particle(glm::vec2 position, glm::vec2 velocity, float particle_radius,
           float mass, cinder::Color color);

  static void HandleParticleCollisions(Particle& particle,
                                       std::vector<Particle>& particles);

  /**
   * Gets the radius
   * @return the radius
   */
  float get_particle_radius() const;

  /**
   * Checks whether two particles are the same.
   * @param other_particle
   * @return True if the particles are the same.
   */
  bool operator==(Particle other_particle) const;

  /**
   * Executes the collision of the particle with a horizontal wall.
   */
  void CollideHorizontalWall();

  /**
   * Executes the collision of the particle with a vertical wall.
   */
  void CollideVerticalWall();

  const glm::vec2& get_position() const;
  void set_position(const glm::vec2& position);

  const glm::vec2& get_velocity() const;
  void set_velocity(const glm::vec2& velocity);

  float get_mass() const;
  const ci::Color& get_color() const;

  /**
   * Calculates the speed of the particle using
   * the velocity vector.
   * @return speed as a float.
   */
  float CalculateSpeed() const;

 private:
  /**
   * The 2d vectors representing the position and velocity of each particle.
   */
  glm::vec2 position_;
  glm::vec2 velocity_;

  float particle_radius_;
  float mass_;
  ci::Color color_;

  /**
   * Calculates the velocity of a particle after colliding with another
   * particle.
   * @param particle The first particle
   * @param colliding_particle The particle it's colliding with.
   * @return Returns the velocity of the actual
   */
  void CollideParticles(Particle colliding_particle);
};
