#include <gas_container.h>

#include <catch2/catch.hpp>

using glm::vec2;
using idealgas::GasContainer;
using std::vector;

TEST_CASE("Testing Particle Collision") {
  SECTION("Particle collision not executed") {
    vector<Particle> particles;

    particles.push_back(
        Particle(vec2(147, 4), vec2(5, 0), 3, 14, ci::Color("orange")));
    particles.push_back(
        Particle(vec2(163, 4), vec2(-5, 0), 3, 7, ci::Color("yellow")));
    GasContainer container(particles);
    container.AdvanceOneFrame();

    REQUIRE(fabs(container.get_particles().at(0).get_velocity().x -
                 (-1.66667)) < ci::EPSILON_VALUE);
    REQUIRE(container.get_particles().at(0).get_velocity().y == 0);
    REQUIRE(fabs(container.get_particles().at(1).get_velocity().x -
                 (8.333333)) < ci::EPSILON_VALUE);
    REQUIRE(container.get_particles().at(1).get_velocity().y == 0);
  }

  SECTION("Particle collision executed") {
    vector<Particle> particles;

    particles.push_back(
        Particle(vec2(147, 4), vec2(12, 2), 20, 1, ci::Color("orange")));
    particles.push_back(
        Particle(vec2(158, 4), vec2(3, 4), 20, 2, ci::Color("orange")));

    GasContainer container(particles);
    container.AdvanceOneFrame();

    REQUIRE(fabs(container.get_particles().at(0).get_velocity().x - (7.33333)) <
            ci::EPSILON_VALUE);
    REQUIRE(fabs(container.get_particles().at(0).get_velocity().y -
                 (-2.666667)) < ci::EPSILON_VALUE);
    REQUIRE(fabs(container.get_particles().at(1).get_velocity().x -
                 (5.333333)) < ci::EPSILON_VALUE);
    REQUIRE(fabs(container.get_particles().at(1).get_velocity().y - (6.33333)) <
            ci::EPSILON_VALUE);
  }

  SECTION("More than two particles") {
    vector<Particle> particles;
    Particle first_particle(vec2(150, 300), vec2(2, 3), 5, 4,
                            ci::Color("orange"));
    Particle second_particle(vec2(160, 300), vec2(-2, 3), 5, 12,
                             ci::Color("orange"));
    Particle third_particle(vec2(155, 305 + sqrt(3)), vec2(0, -3), 5, 12,
                            ci::Color("orange"));
    particles.push_back(first_particle);
    particles.push_back(second_particle);
    particles.push_back(third_particle);

    GasContainer container(particles);
    container.AdvanceOneFrame();

    REQUIRE(container.get_particles().at(0).get_velocity().x == -4.0);
    REQUIRE(container.get_particles().at(0).get_velocity().y == 3);

    REQUIRE(container.get_particles().at(1).get_velocity().x - (1.38183) < ci::EPSILON_VALUE);
    REQUIRE(container.get_particles().at(1).get_velocity().y - (2.66281) < ci::EPSILON_VALUE);

    REQUIRE(container.get_particles().at(2).get_velocity().x - (-1.38183) < ci::EPSILON_VALUE);
    REQUIRE(container.get_particles().at(2).get_velocity().y - (-2.66281) < ci::EPSILON_VALUE);
  }
}

TEST_CASE("Testing Wall Collisions") {
  SECTION("Horizontal Wall Collision, away from the wall") {
    vector<Particle> particles;
    Particle particle(vec2(100, 130), vec2(5, 3), 5, 12, ci::Color("orange"));
    particles.push_back(particle);
    GasContainer container(particles);
    container.AdvanceOneFrame();
    REQUIRE(container.get_particles().at(0).get_velocity().x == 5);
    REQUIRE(container.get_particles().at(0).get_velocity().y == 3);
  }

  SECTION("Horizontal Wall Collision, towards the wall") {
    vector<Particle> particles;
    Particle particle(vec2(100, 130), vec2(-5, 1), 5, 25, ci::Color("orange"));
    particles.push_back(particle);
    GasContainer container(particles);
    container.AdvanceOneFrame();
    REQUIRE(container.get_particles().at(0).get_velocity().x == 5);
    REQUIRE(container.get_particles().at(0).get_velocity().y == 1);
  }

  SECTION("Vertical Wall Collision, away from the wall") {
    vector<Particle> particles;
    Particle particle(vec2(400, 400), vec2(12, -17), 5, 11,
                      ci::Color("orange"));
    particles.push_back(particle);
    GasContainer container(particles);
    container.AdvanceOneFrame();
    REQUIRE(container.get_particles().at(0).get_velocity().x == 12);
    REQUIRE(container.get_particles().at(0).get_velocity().y == -17);
  }

  SECTION("Vertical Wall Collision, towards the wall") {
    vector<Particle> particles;
    Particle particle(vec2(175, 100), vec2(5, -17), 5, 13, ci::Color("orange"));
    particles.push_back(particle);
    GasContainer container(particles);
    container.AdvanceOneFrame();
    REQUIRE(container.get_particles().at(0).get_velocity().x == 5);
    REQUIRE(container.get_particles().at(0).get_velocity().y == 17);
  }

  SECTION("Corner collision, away from the corner") {
    vector<Particle> particles;
    Particle particle(vec2(100, 100), vec2(15, 15), 5, 4, ci::Color("orange"));
    particles.push_back(particle);
    GasContainer container(particles);
    container.AdvanceOneFrame();
    REQUIRE(container.get_particles().at(0).get_velocity().x == 15);
    REQUIRE(container.get_particles().at(0).get_velocity().y == 15);
  }

  SECTION("Corner collision, towards the corner") {
    vector<Particle> particles;
    Particle particle(vec2(600, 0), vec2(12, -18), 5, 13, ci::Color("orange"));
    particles.push_back(particle);
    GasContainer container(particles);
    container.AdvanceOneFrame();
    REQUIRE(container.get_particles().at(0).get_velocity().x == -12);
    REQUIRE(container.get_particles().at(0).get_velocity().y == 18);
  }
}

TEST_CASE("Position Updated") {
  vector<Particle> particles;
  Particle particle(vec2(175, 100), vec2(5, -17), 5, 13, ci::Color("orange"));
  particles.push_back(particle);
  GasContainer container(particles);
  container.AdvanceOneFrame();
  REQUIRE(container.get_particles().at(0).get_position().x == 180.0);
  REQUIRE(container.get_particles().at(0).get_position().y == 83.0);
}
