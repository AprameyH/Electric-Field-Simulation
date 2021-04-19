#include "histogram.h"

#include <particle.h>

#include "cinder/gl/gl.h"
using ci::Color;
using glm::vec2;
using std::map;
using std::vector;

Histogram::Histogram(vector<Particle> histo_particles, vec2 starting_pos) {
  starting_pos_ = starting_pos;
  red_list_ = SortByColor(histo_particles, Color("red"));
  green_list_ = SortByColor(histo_particles, Color("green"));
  blue_list_ = SortByColor(histo_particles, Color("blue"));
}

void Histogram::Reveal() const {
  DrawHistogram(vec2(starting_pos_.x, starting_pos_.y), red_list_);

  DrawHistogram(vec2(starting_pos_.x + kSpaceBetween, starting_pos_.y),
                green_list_);

  DrawHistogram(vec2(starting_pos_.x + kSpaceBetween * 2, starting_pos_.y),
                blue_list_);
}

std::vector<Particle> Histogram::SortByColor(vector<Particle> particles,
                                             Color sort_color) const {
  vector<Particle> sorted_list;

  for (Particle &particle : particles) {
    if (particle.get_color() == sort_color) {
      sorted_list.push_back(particle);
    }
  }

  return sorted_list;
}

std::vector<float> Histogram::SortBySpeed(vector<Particle> particles) const {
  vector<float> heights{0, 0, 0, 0, 0};

  for (Particle &particle : particles) {
    if (particle.CalculateSpeed() > kFourthBin) {
      heights.at(4)++;
    } else if (particle.CalculateSpeed() > kThirdBin) {
      heights.at(3)++;
    } else if (particle.CalculateSpeed() > kSecondBin) {
      heights.at(2)++;
    } else if (particle.CalculateSpeed() > kFirstBin) {
      heights.at(1)++;
    } else {
      heights.at(0)++;
    }
  }

  for (size_t i = 0; i < heights.size(); i++) {
    heights.at(i) *= kHeightProportion;
  }
  return heights;
}

void Histogram::DrawHistogram(vec2 starting_pos,
                              vector<Particle> particles) const {
  vector<float> heights = SortBySpeed(particles);
  Color color = particles.at(0).get_color();
  ci::gl::color(color);
  int count = 1;
  for (float height : heights) {
    ci::gl::drawSolidRect(ci::Rectf(
        vec2(starting_pos.x + (count - 1) * bar_width, starting_pos.y),
        vec2(starting_pos.x + count * bar_width, starting_pos.y - height)));

    ci::gl::drawString(
        std::to_string(kBins.at(count - 1)),
        vec2(starting_pos.x + ((count - 1) * bar_width) + bar_width / 2,
             starting_pos.y + bar_width / 5));

    count++;
  }

  for (size_t i = 0; i <= particles.size(); i++) {
    ci::gl::drawString(std::to_string(i),
                       vec2(starting_pos.x - bar_width,
                            starting_pos.y - (i * kHeightProportion)));
  }
}
