#pragma once

#include <vector>
#include "charge.h"
#include "arrow.h"
#include "math.h"

namespace chargefield {
class ElectricField {
public:
    ElectricField(std::vector<Arrow> arrow_layout, std::vector<Charge> charge_layout);

    void Display() const;

    glm::vec2 CalculateFieldDirection(glm::vec2 arrow_position) const;

    glm::vec2 FindDirection(glm::vec2 field, glm::vec2 arrow_pos) const;

    void RemoveCharge(Charge &charge);
    void AddCharge(Charge &charge);

    std::vector<Charge> &get_charge_layout();

    const int get_charge_radius() const;
    const glm::vec2 &get_first_corner() const;
    const glm::vec2 &get_second_corner() const;

    const glm::vec2 kPositiveSpawn{400, 150};
    const glm::vec2 kNegativeSpawn{500, 150};

    bool IsSpawnOccupied(int charge_val);


private:
    std::vector<Arrow> arrow_layout_;
    std::vector<Charge> charge_layout_;

    const glm::vec2 kFirstCorner{100, 100};

    const glm::vec2 kSecondCorner{800, 800};

    const int kChargeRadius = 7;
    const double kCoulomb = 8.988 * pow(10, 9);
    const double kPi = atan(1) * 4;
};
}


