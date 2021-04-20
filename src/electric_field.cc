#include <arrow.h>
#include <cinder/gl/wrapper.h>
#include <cinder/gl/gl.h>
#include "electric_field.h"

namespace chargefield {
    chargefield::ElectricField::ElectricField(const std::vector<Arrow> &arrowLayout) : arrow_layout_(arrowLayout) {}

    void chargefield::ElectricField::Display() const {
        for (Arrow arrow : arrow_layout_) {
            arrow.DrawArrow(glm::vec2(500, 500));
        }

        ci::gl::drawSolidCircle(glm::vec2(500,500), 5);
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(kFirstCorner, kSecondCorner));
    }

    void chargefield::ElectricField::AdvanceOneFrame() {

    }
}