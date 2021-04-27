#include <arrow.h>
#include <cinder/gl/wrapper.h>
#include <cinder/gl/gl.h>

#include <utility>
#include "electric_field.h"

namespace chargefield {
    chargefield::ElectricField::ElectricField(std::vector<Arrow> arrow_layout, std::vector<Charge> charge_layout)
            : arrow_layout_(std::move(arrow_layout)),
              charge_layout_(std::move(charge_layout)) {
    }

    void chargefield::ElectricField::Display() const {
        for (Arrow arrow : arrow_layout_) {
            glm::vec2 field = CalculateFieldDirection(arrow.get_position());
            glm::vec2 direction = FindDirection(field, arrow.get_position());
            arrow.DrawArrow(direction);
        }

        for (const Charge &charge : charge_layout_) {
            if (charge.is_positive()) {
                ci::gl::color(ci::Color("red"));
            } else {
                ci::gl::color(ci::Color("blue"));
            }
            ci::gl::drawSolidCircle(charge.get_position(), charge_radius_);
            ci::gl::drawStrokedCircle(charge.get_position(), charge_radius_);
        }

        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(kFirstCorner, kSecondCorner));

    }

    void chargefield::ElectricField::AdvanceOneFrame() {

    }

    glm::vec2 ElectricField::CalculateFieldDirection(glm::vec2 arrow_position) const {
        //Todo: Seems to not be working to the right of the particles.
        double total_x_component = 0;
        double total_y_component = 0;

        for (const Charge &charge : charge_layout_) {
            //Calculate the x and y components due to each charge.
            double init_magnitude =
                    (kCoulomb * charge.get_charge_val()) / pow(distance(arrow_position, charge.get_position()), 2);

//            double y_dif = charge.get_position().y - arrow_position.y;
//            double x_dif = charge.get_position().x - arrow_position.x;
            double y_dif = arrow_position.y - charge.get_position().y;
            double x_dif = arrow_position.x - charge.get_position().x;
            double init_angle = atan(y_dif / x_dif);

            double x_component = init_magnitude * cos(init_angle);
            double y_component = init_magnitude * sin(init_angle);

            total_x_component = total_x_component + x_component;
            total_y_component = total_y_component + y_component;
        }

        //Todo: If the magnitude is negative, reverse the angle somehow.

        return glm::vec2(total_x_component, total_y_component);
    }

    glm::vec2 ElectricField::FindDirection(glm::vec2 field, glm::vec2 arrow_pos) const {
        glm::vec2 end_point = arrow_pos + field;

        return end_point;
//return glm::vec2();
    }
}