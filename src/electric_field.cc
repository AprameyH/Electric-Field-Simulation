#include <arrow.h>
#include <cinder/gl/wrapper.h>
#include <cinder/gl/gl.h>
#include "electric_field.h"

namespace chargefield {
    chargefield::ElectricField::ElectricField(const std::vector<Arrow> &arrowLayout) : arrow_layout_(arrowLayout), charge_pos_(200,500) {
    }

    void chargefield::ElectricField::Display() const {
        for (Arrow arrow : arrow_layout_) {
            arrow.DrawArrow(charge_pos_);
        }

        ci::gl::drawSolidCircle(charge_pos_, charge_radius_);
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(kFirstCorner, kSecondCorner));
    }

    void chargefield::ElectricField::AdvanceOneFrame() {

    }
}