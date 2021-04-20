#include <gas_container.h>

#include <catch2/catch.hpp>

using ::Particle;
using glm::vec2;

TEST_CASE("Testing the compare method") {
  SECTION("Same particle") {
    Particle particle(vec2(7.5, 3.5), vec2(23.4, 45.4), 3.3, 1,
                      ci::Color("red"));
    Particle other_particle = particle;
    REQUIRE(particle == other_particle);
  }

  SECTION("Different position, same radius, color, and mass") {
    Particle particle(vec2(200, 300), vec2(23.4, 45.4), 3.3, 1,
                      ci::Color("red"));
    Particle other_particle(vec2(7.5, 3.5), vec2(23.4, 45.4), 3.3, 1,
                            ci::Color("red"));
    REQUIRE(!(particle == other_particle));
  }

  SECTION("Same position, different radius and same velocity") {
    Particle particle(vec2(200, 300), vec2(23.4, 45.4), 7, 1, ci::Color("red"));
    Particle other_particle(vec2(200, 300), vec2(23.4, 45.4), 3.3, 1,
                            ci::Color("red"));
    REQUIRE(!(particle == other_particle));
  }

  SECTION("Same position, same radius, same color and different mass") {
    Particle particle(vec2(200, 300), vec2(5, 45.4), 7, 1, ci::Color("red"));
    Particle other_particle(vec2(200, 300), vec2(23.4, 45.4), 7, 1,
                            ci::Color("red"));
    REQUIRE(!(particle == other_particle));
  }

  SECTION("Same position, same radius and different color") {
    Particle particle(vec2(200, 300), vec2(5, 45.4), 7, 1, ci::Color("red"));
    Particle other_particle(vec2(200, 300), vec2(23.4, 45.4), 7, 1,
                            ci::Color("blue"));
    REQUIRE(!(particle == other_particle));
  }
}
TEST_CASE("Testing Handle Collisions") {
  SECTION("Moving away from each other") {
    std::vector<Particle> particles;
    vec2 originalVelocity(5, 5);
    Particle left_particle(vec2(-100, 100), originalVelocity, 5, 12,
                           ci::Color("orange"));
    Particle right_particle(vec2(-110, 100), vec2(3, 10), 5, 4,
                            ci::Color("orange"));
    Particle::HandleParticleCollisions(left_particle, particles);

    REQUIRE(left_particle.get_velocity() == originalVelocity);
  }

  SECTION("Particles moving towards each other") {
    std::vector<Particle> particles;
    Particle left_particle(vec2(6, 7), vec2(-6, -2), 5, 4, ci::Color("orange"));
    Particle right_particle(vec2(-4, 7), vec2(12, 3), 5, 12,
                            ci::Color("orange"));
    particles.push_back(left_particle);
    particles.push_back(right_particle);

    Particle::HandleParticleCollisions(left_particle, particles);
    REQUIRE(left_particle.get_velocity().x == 21.0);
    REQUIRE(left_particle.get_velocity().y == -2.0);
  }
}

TEST_CASE("Test Calculate Speed") {
  Particle particle(vec2(6, 7), vec2(3, -4), 5, 4, ci::Color("orange"));
  REQUIRE(particle.CalculateSpeed() == 5);
}