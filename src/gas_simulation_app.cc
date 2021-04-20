#include "gas_simulation_app.h"

#include <histogram.h>
using glm::vec2;
using std::vector;

namespace idealgas {

IdealGasApp::IdealGasApp() : container_(GenerateParticleList()) {
  ci::app::setWindowSize(kWindowSize, kMargin);
}

void IdealGasApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  container_.Display();
  Histogram first_histogram(container_.get_particles(), vec2(100, 700));
  first_histogram.Reveal();
}

void IdealGasApp::update() {
  container_.AdvanceOneFrame();
}

void IdealGasApp::keyDown(ci::app::KeyEvent event) {
  if (event.getCode() == ci::app::KeyEvent::KEY_UP) {
    vector<Particle> particles;

    for (Particle const &particle : container_.get_particles()) {
      particles.emplace_back(particle.get_position(),
                             particle.get_velocity() * speed_up,
                             particle.get_particle_radius(),
                             particle.get_mass(), particle.get_color());
    }
    container_.set_particles(particles);

  } else if (event.getCode() == ci::app::KeyEvent::KEY_DOWN) {
    vector<Particle> particles;

    for (Particle const &particle : container_.get_particles()) {
      particles.emplace_back(particle.get_position(),
                             particle.get_velocity() / speed_up,
                             particle.get_particle_radius(),
                             particle.get_mass(), particle.get_color());
    }
    container_.set_particles(particles);
  }
}

vector<Particle> IdealGasApp::GenerateParticleList() const {
  const size_t kNumParticlesType = 10;

  srand(static_cast<unsigned>(time(0)));
  vector<Particle> particles;

  for (size_t i = 0; i < kNumParticlesType; i++) {
    const int margin = 50;
    // Sets the position and mass of the particle to random values.
    const unsigned int random_x =
        (rand() % static_cast<int>(GasContainer::getKSecondCorner().x -
                                   GasContainer::getKFirstCorner().x) -
         margin) +
        static_cast<int>(GasContainer::getKFirstCorner().x) + margin;

    const unsigned int random_y =
        (rand() % static_cast<int>(GasContainer::getKSecondCorner().y -
                                   GasContainer::getKFirstCorner().y) -
         margin) +
        static_cast<int>(GasContainer::getKFirstCorner().y) + margin;

    const float mass = 24;
    const vec2 position(random_x, random_y);
    const vec2 velocity(2, 2);
    const float radius = 10;

    Particle particle(position, velocity, radius, mass, ci::Color("red"));
    particles.push_back(particle);
  }

  for (size_t i = 0; i < kNumParticlesType; i++) {
    const int margin = 50;
    // Sets the position and mass of the particle to random values.
    const unsigned int random_x =
        (rand() % static_cast<int>(GasContainer::getKSecondCorner().x -
                                   GasContainer::getKFirstCorner().x) -
         margin) +
        static_cast<int>(GasContainer::getKFirstCorner().x) + margin;

    const unsigned int random_y =
        (rand() % static_cast<int>(GasContainer::getKSecondCorner().y -
                                   GasContainer::getKFirstCorner().y) -
         margin) +
        static_cast<int>(GasContainer::getKFirstCorner().y) + margin;

    const float mass = 12;
    const vec2 position(random_x, random_y);
    const vec2 velocity(2, 2);

    const float radius = 8;
    Particle particle(position, velocity, radius, mass, ci::Color("green"));
    particles.push_back(particle);
  }

  for (size_t i = 0; i < kNumParticlesType; i++) {
    const int margin = 50;

    // Sets the position and mass of the particle to random values.
    const unsigned int random_x =
        (rand() % static_cast<int>(GasContainer::getKSecondCorner().x -
                                   GasContainer::getKFirstCorner().x) -
         margin) +
        static_cast<int>(GasContainer::getKFirstCorner().x) + margin;
    const unsigned int random_y =
        (rand() % static_cast<int>(GasContainer::getKSecondCorner().y -
                                   GasContainer::getKFirstCorner().y) -
         margin) +
        static_cast<int>(GasContainer::getKFirstCorner().y) + margin;

    const float mass = 6;
    const vec2 position(random_x, random_y);
    const vec2 velocity(2, 2);

    const float radius = 6;
    Particle particle(position, velocity, radius, mass, ci::Color("blue"));
    particles.push_back(particle);
  }

  return particles;
}

}  // namespace idealgas
