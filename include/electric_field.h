#pragma once

#include <vector>
#include "charge.h"

namespace chargefield {
    class ElectricField {
    public:
        ElectricField(std::vector<Arrow> arrow_layout, std::vector<Charge> charge_layout);

        void Display() const;

        void AdvanceOneFrame();

    private:
        std::vector<Arrow> arrow_layout_;
        std::vector<Charge> charge_layout_;

        const glm::vec2 kFirstCorner{100, 100};
        const glm::vec2 kSecondCorner{800, 800};

        const int charge_radius_ = 5;
        const double kCoulomb = 8.988 * pow(10,9);

        std::pair<double, double> CalculateFieldDirection(glm::vec2 arrow_position) const;

        glm::vec2 FindDirection(double angle, glm::vec2 arrow_pos) const;

    };
}


