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
        //ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(kFirstCorner, kSecondCorner));

        for (Arrow arrow : arrow_layout_) {
            arrow.DrawArrow(FindDirection(CalculateFieldDirection(arrow.get_position()).second,arrow.get_position()));
            ci::gl::drawSolidCircle(arrow.get_position(), charge_radius_);
        }

        for (const Charge &charge : charge_layout_) {
            if (charge.is_positive()) {
                //ci::gl::color(ci::Color("blue"));
            } else {
                //ci::gl::color(ci::Color("red"));
            }
            ci::gl::drawSolidCircle(charge.get_position(), charge_radius_);
            //ci::gl::color(ci::Color("white"));
        }


    }

    void chargefield::ElectricField::AdvanceOneFrame() {

    }

    std::pair<double, double> ElectricField::CalculateFieldDirection(glm::vec2 arrow_position) const {
        double total_x_component = 0;
        double total_y_component = 0;

        for (const Charge &charge : charge_layout_) {
            //Calculate the x and y components due to each charge.
            double init_magnitude =
                    (kCoulomb * charge.get_charge_val()) / pow(distance(arrow_position, charge.get_position()), 2);

            double y_dif = charge.get_position().y - arrow_position.y;
            double x_dif = charge.get_position().x - arrow_position.x;
            double init_angle = atan(y_dif / x_dif);

            double x_component = init_magnitude * cos(init_angle);
            double y_component = init_magnitude * sin(init_angle);

            total_x_component = total_x_component + x_component;
            total_y_component = total_y_component + y_component;
        }
        double total_magnitude = sqrt(pow(total_x_component, 2) + pow(total_y_component, 2));
        double total_angle = atan(total_y_component/total_x_component);
        return std::make_pair(total_magnitude, total_angle);
    }

    glm::vec2 ElectricField::FindDirection(double angle, glm::vec2 arrow_pos) const {
        float x_end = 5 * cos(angle) + arrow_pos.x;
        float y_end = 5 * sin(angle) + arrow_pos.y;

        glm::vec2 end_point(x_end, y_end);
        return end_point;
    }
}