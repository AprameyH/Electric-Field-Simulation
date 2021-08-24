#pragma once

#include <vector>
#include "charge.h"
#include "arrow.h"
#include "math.h"

namespace chargefield {
class ElectricField {
public:
    ElectricField(std::vector<Arrow> arrow_layout, std::vector<Charge> charge_layout);

    /**
     * Displays arrows according to the magnitude of the vector field at their
     * position. A stronger vector field is more solid while a weak vector field
     * is invisible.
     */
    void Display() const;

    /**
     * Calculates the direction of the vector field at a given location.
     * Uses the electric field formula to evaluate the field components due to
     * each charge and then combines them to find the total electric field.
     * @param arrow_position The position for which the vector field is calculated.
     * @return A vector representing the electric field at that point.
     */
    glm::vec2 CalculateFieldDirection(glm::vec2 arrow_position) const;

    /**
     * Converts the vector field at the point into a direction
     * that can be used to draw an arrow.
     * @param field The field at the point.
     * @param arrow_pos The location of the arrow.
     * @return A vector representing the direction of the arrow.
     */
    glm::vec2 FindDirection(glm::vec2 field, glm::vec2 arrow_pos) const;

    /**
     * Calculates the magnitude of the electric field using the field vector
     * @param field The field vector at a specified point.
     * @return The magnitude as a float.
     */
    float CalculateMagnitude(glm::vec2 field) const;

    /**
     * Removes a charge from the electric field.
     * @param charge
     */
    void RemoveCharge(Charge &charge);

    /**
     * Adds a charge to the simulation.
     * @param charge
     */
    void AddCharge(Charge &charge);

    std::vector<Charge> &get_charge_layout();
    const int get_charge_radius() const;

    /**
     * Field container coordinates.
     * @return
     */
    const glm::vec2 &get_first_corner() const;
    const glm::vec2 &get_second_corner() const;

    /**
     * Coordinates of the charge spawn locations.
     * @return
     */
    const glm::vec2 &get_positive_spawn() const;
    const glm::vec2 &get_negative_spawn() const;

    /**
     * Checks whether there is already a charge of a particular type
     * at the spawn position.
     * @param charge_val Whether the charge is positive or negative
     * @return True if the spawn is occupied.
     */
    bool IsSpawnOccupied(bool is_positive);


private:
    std::vector<Arrow> arrow_layout_;
    std::vector<Charge> charge_layout_;

    const glm::vec2 kFirstCorner{100, 100};

    const glm::vec2 kSecondCorner{800, 800};

    const int kChargeRadius = 7;
    const double kCoulomb = 8.988e9;
    const double kPi = atan(1) * 4;

    /**
     * The color is set according to the magnitude adjusted by kSaturation.
     */
    const float kSaturation = 1250000;

    const glm::vec2 kPositiveSpawn{338, 750};
    const glm::vec2 kNegativeSpawn{563, 750};
};
}


