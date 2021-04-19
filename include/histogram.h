#pragma once

#include "cinder/gl/gl.h"
#include "particle.h"

class Histogram {
 public:
  Histogram(std::vector<Particle> histo_particles, glm::vec2 starting_pos);

  /**
   * Draws the three histograms
   */
  void Reveal() const;

  /**
   * Filters the particles according to the passed color.
   * @param particles All particles
   * @param sort_color Color by which to filter
   * @return a vector containing only one type of particle.
   */
  std::vector<Particle> SortByColor(std::vector<Particle> particles,
                                    ci::Color sort_color) const;

  /**
   * Sorts the particles into bins according to speed.
   * @param particles
   * @return a vector containing the heights of each bin.
   */
  std::vector<float> SortBySpeed(std::vector<Particle> particles) const;

 private:
  glm::vec2 starting_pos_;
  const int bar_width = 25;

  std::vector<Particle> red_list_;
  std::vector<Particle> green_list_;
  std::vector<Particle> blue_list_;


  /**
   * Draws a histogram by calling the sortbyspeed function.
   * @param starting_pos the position on screen for the histogram.
   * @param particles a list of particles
   */
  void DrawHistogram(glm::vec2 starting_pos,
                     std::vector<Particle> particles) const;

  const std::vector<int> kBins{0, 1, 3, 5, 7};
  const float kFirstBin = kBins.at(1);
  const float kSecondBin = kBins.at(2);
  const float kThirdBin = kBins.at(3);
  const float kFourthBin = kBins.at(4);
  /**
   * The scale of the histogram.
   */
  const int kHeightProportion = 15;
  const int kSpaceBetween = 200;
};
