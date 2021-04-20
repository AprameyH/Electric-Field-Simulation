
#include "particle.h"
using glm::vec2;

Particle::Particle(vec2 position, vec2 velocity, float particle_radius,
                   float mass, ci::Color color) {
  particle_radius_ = particle_radius;
  position_ = position;
  velocity_ = velocity;
  mass_ = mass;
  color_ = color;
}

bool Particle::operator==(Particle other_particle) const {
  return position_ == other_particle.get_position() &&
         velocity_ == other_particle.get_velocity() &&
         mass_ == other_particle.get_mass() &&
         particle_radius_ == other_particle.get_particle_radius() &&
         color_ == other_particle.get_color();
}

void Particle::CollideHorizontalWall() {
  velocity_.x *= -1;
}

void Particle::CollideVerticalWall() {
  velocity_.y *= -1;
}

void Particle::CollideParticles(Particle colliding_particle) {
  const vec2 velocity_difference = velocity_ - colliding_particle.velocity_;
  const vec2 position_difference = position_ - colliding_particle.position_;

  if (dot(velocity_difference, position_difference) <= 0) {
    const float dot_ratio =
        dot(velocity_difference, position_difference) /
        (length(position_difference) * length(position_difference));
    const float mass_ratio = (2 * colliding_particle.get_mass()) /
                             (mass_ + colliding_particle.get_mass());

    vec2 finalVelocity =
        velocity_ - (mass_ratio * (dot_ratio * position_difference));
    velocity_ = finalVelocity;
  }
}

float Particle::CalculateSpeed() const {
  return length(velocity_);
}

float Particle::get_particle_radius() const {
  return particle_radius_;
}
const vec2& Particle::get_position() const {
  return position_;
}
void Particle::set_position(const vec2& position) {
  position_ = position;
}
const vec2& Particle::get_velocity() const {
  return velocity_;
}

void Particle::set_velocity(const vec2& velocity) {
  velocity_ = velocity;
}

float Particle::get_mass() const {
  return mass_;
}

const ci::Color& Particle::get_color() const {
  return color_;
}

void Particle::HandleParticleCollisions(Particle& particle,
                                        std::vector<Particle>& particles) {
  for (Particle& other_particle : particles) {
    if (!(particle == other_particle) &&
        distance(particle.get_position(), other_particle.get_position()) <=
            particle.get_particle_radius() +
                other_particle.get_particle_radius()) {
      Particle temp_particle = particle;
      particle.CollideParticles(other_particle);
      other_particle.CollideParticles(temp_particle);
    }
  }
}
