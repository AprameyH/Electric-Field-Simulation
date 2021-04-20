#include <arrow.h>
#include "electric_field.h"

namespace chargefield {
    chargefield::ElectricField::ElectricField(const std::vector<Arrow> &arrowLayout) : arrow_layout_(arrowLayout) {}

    void chargefield::ElectricField::Display() const {
        for (Arrow arrow : arrow_layout_) {
            arrow.DrawArrow(glm::vec2(500, 500));
        }
    }

    void chargefield::ElectricField::AdvanceOneFrame() {

    }
}