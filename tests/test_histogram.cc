#include <histogram.h>

#include <catch2/catch.hpp>
using glm::vec2;
using std::vector;
TEST_CASE("Test Sort By Color") {
  SECTION("Same color particles") {
    Particle first_particle(vec2(5, 4), vec2(3, 4), 12, 10, ci::Color("red"));
    Particle second_particle(vec2(2, 1), vec2(3, 4), 12, 10, ci::Color("red"));
    Particle third_particle(vec2(0, 0), vec2(3, 4), 12, 10, ci::Color("red"));
    vector<Particle> particles{first_particle, second_particle};
    Histogram histogram(particles, glm::vec2(5, 4));
    REQUIRE(histogram.SortByColor(particles, ci::Color("red")) == particles);
  }

  SECTION("Multiple colors") {
    Particle first_particle(vec2(5, 4), vec2(3, 4), 12, 10, ci::Color("green"));
    Particle second_particle(vec2(2, 1), vec2(3, 4), 12, 10, ci::Color("blue"));
    Particle third_particle(vec2(0, 0), vec2(3, 4), 12, 10, ci::Color("green"));

    vector<Particle> particles;
    particles.push_back(first_particle);
    particles.push_back(second_particle);
    particles.push_back(third_particle);

    Histogram histogram(particles, glm::vec2(5, 4));
    REQUIRE(histogram.SortByColor(particles, ci::Color("green")).at(0) ==
            first_particle);
    REQUIRE(histogram.SortByColor(particles, ci::Color("green")).at(1) ==
            third_particle);
    REQUIRE(histogram.SortByColor(particles, ci::Color("green")).size() == 2);
  }

  SECTION("No colors of selected type") {
    Particle first_particle(vec2(5, 4), vec2(3, 4), 12, 10,
                            ci::Color("orange"));
    Particle second_particle(vec2(2, 1), vec2(3, 4), 12, 10,
                             ci::Color("yellow"));
    Particle third_particle(vec2(0, 0), vec2(3, 4), 12, 10, ci::Color("green"));

    vector<Particle> particles;
    particles.push_back(first_particle);
    particles.push_back(second_particle);
    particles.push_back(third_particle);

    Histogram histogram(particles, vec2(5, 4));
    REQUIRE(histogram.SortByColor(particles, ci::Color("red")) ==
            vector<Particle>{});
  }
}

TEST_CASE("Test Sort by Speed") {
  SECTION("Stationary Particles") {
    Particle first_particle(vec2(5, 4), vec2(0, 0), 12, 10, ci::Color("green"));
    Particle second_particle(vec2(2, 1), vec2(0, 0), 12, 10, ci::Color("blue"));
    Particle third_particle(vec2(0, 0), vec2(0, 0), 12, 10, ci::Color("green"));

    vector<Particle> particles;
    particles.push_back(first_particle);
    particles.push_back(second_particle);
    particles.push_back(third_particle);

    Histogram histogram(particles, vec2(100, 100));
    REQUIRE(histogram.SortBySpeed(particles) == vector<float>{45, 0, 0, 0, 0});
  }

  SECTION("Particle spread") {
    Particle first_particle(vec2(5, 4), vec2(4, 8), 12, 10, ci::Color("green"));
    Particle second_particle(vec2(2, 1), vec2(1, 1), 12, 10, ci::Color("blue"));
    Particle third_particle(vec2(0, 0), vec2(2, 5), 12, 10, ci::Color("green"));
    Particle fourth_particle(vec2(5, 4), vec2(6, 3), 12, 10, ci::Color("green"));
    Particle fifth_particle(vec2(2, 1), vec2(0, 1), 12, 10, ci::Color("blue"));
    Particle sixth_particle(vec2(0, 0), vec2(3, 2), 12, 10, ci::Color("green"));
    vector<Particle> particles;

    particles.push_back(first_particle);
    particles.push_back(second_particle);
    particles.push_back(third_particle);
    particles.push_back(fourth_particle);
    particles.push_back(fifth_particle);
    particles.push_back(sixth_particle);

    Histogram histogram(particles, vec2(100, 100));
    REQUIRE(histogram.SortBySpeed(particles) == vector<float>{15, 15, 15, 30, 15});
  }
}
