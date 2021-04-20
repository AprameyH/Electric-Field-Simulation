#pragma once

#include <vector>

namespace chargefield {
    class ElectricField {
    public:
        explicit ElectricField(const std::vector <Arrow> &arrowLayout);

        void Display() const;

        void AdvanceOneFrame();

        const glm::vec2 kFirstCorner{100, 100};
        const glm::vec2 kSecondCorner{800, 800};
    private:
        std::vector<Arrow> arrow_layout_;
    };
}


