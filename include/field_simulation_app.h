#pragma once

#include "cinder/app/App.h"
#include "arrow.h"
#include "electric_field.h"

namespace chargefield {
/**
 * An app for visualizing interactions between charged particles and fields.
 */
class ElectricFieldApp : public ci::app::App {

public:
    ElectricFieldApp();

    void draw() override;

    /**
     * Tracks the position of the mouse as it is dragged across the simulation.
     * Used to move and reposition charges.
     * @param event
     */
    void mouseDrag(cinder::app::MouseEvent event) override;

    /**
     * Used to add a charged particle to the simulation.
     * Spawns a charged particle when the user clicks on one of the icons at the bottom.
     * Once a particle of a particular type has been added, no more particles
     * of that type can be added until the added particle is moved.
     * @param event
     */
    void mouseDown(cinder::app::MouseEvent event) override;

    /**
     * The method generates the initial set of arrows.
     * Used to initialize a container object.
     * @return a vector of Arrow objects.
     */
    std::vector<Arrow> GenerateArrowList() const;

    /**
     * Can be used to visualize a simulation of particles in specified locations.
     * Charges added in this method will be displayed when the simulation
     * is run, without having to add them manually.
     * @return the vector of Charges that will be displayed.
     */
    std::vector<Charge> GenerateChargeList() const;

private:
    const int kWindowSize = 1000;
    const int kMargin = 900;

    const int kNumArrows = 81;
    const int kArrowMargin = 150;

    ElectricField electric_field_;

    /**
     * The positions of the source charges seen at the bottom of the screen.
     */
    const glm::vec2 kPositiveSource{400, 825};
    const glm::vec2 kNegativeSource{450, 825};
    const float kBelowSource = 50;

    const std::string initial_instructions = "Click on the red circle to add a positive charge to the electric field. Click on the blue circle to add a negative charge to the electric field.\n Remove a charge by dragging it outside the box.";

    /**
     * Vector containing the source charges.
     */
    std::vector<Charge> source_charge_layout_;
};

}


