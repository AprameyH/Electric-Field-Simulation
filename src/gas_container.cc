#include "gas_container.h"

namespace idealgas {

using glm::vec2;
using std::vector;

GasContainer::GasContainer(vector<Particle> particles) {
  particles_ = particles;
}

void GasContainer::Display() const {
  for (const Particle &particle : particles_) {
    ci::gl::color(ci::Color(particle.get_color()));
    ci::gl::drawSolidCircle(particle.get_position(),
                            particle.get_particle_radius());
  }

  ci::gl::color(ci::Color("white"));
  ci::gl::drawStrokedRect(ci::Rectf(kFirstCorner, kSecondCorner));
}

void GasContainer::AdvanceOneFrame() {
  // Loop updating positions
  for (Particle &particle : particles_) {
    particle.set_position(particle.get_position() + particle.get_velocity());
  }
  // Loop updating velocities
  for (Particle &particle : particles_) {
    // Checks for collisions with walls.
    bool touching_right_wall = particle.get_position().x >=
                               kSecondCorner.x - particle.get_particle_radius();
    bool touching_left_wall = particle.get_position().x <=
                              kFirstCorner.x + particle.get_particle_radius();

    if ((touching_right_wall && particle.get_velocity().x > 0) ||
        (touching_left_wall && particle.get_velocity().x < 0)) {
      particle.CollideHorizontalWall();
    }

    bool touching_lower_wall = particle.get_position().y >=
                               kSecondCorner.y - particle.get_particle_radius();
    bool touching_upper_wall = particle.get_position().y <=
                               kFirstCorner.y + particle.get_particle_radius();

    if ((touching_lower_wall && particle.get_velocity().y > 0) ||
        (touching_upper_wall && particle.get_velocity().y < 0)) {
      particle.CollideVerticalWall();
    }

    Particle::HandleParticleCollisions(particle, particles_);
  }
}

std::vector<Particle> const &GasContainer::get_particles() {
  return particles_;
}

void GasContainer::set_particles(std::vector<Particle> particles) {
  particles_ = particles;
}
const vec2 &GasContainer::getKFirstCorner() {
  return kFirstCorner;
}
const vec2 &GasContainer::getKSecondCorner() {
  return kSecondCorner;
}

}  // namespace idealgas
