#pragma once

#include <vector>

namespace chargefield {
    class ElectricField {
    public:
        explicit ElectricField(const std::vector <Arrow> &arrowLayout);

        void Display() const;

        void AdvanceOneFrame();
    private:
        std::vector<Arrow> arrow_layout_;
    };
}


