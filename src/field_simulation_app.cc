#include <cinder/gl/wrapper.h>
#include <cinder/gl/draw.h>
#include "field_simulation_app.h"
#include "cinder/app/App.h"


namespace chargefield {

ElectricFieldApp::ElectricFieldApp() : electric_field_(GenerateArrowList(), GenerateChargeList()) {
    ci::app::setWindowSize(kWindowSize, kMargin);
    Charge positive_source(kPositiveSource, 1);
    Charge negative_source(kNegativeSource, -1);

    source_charge_layout_.push_back(positive_source);
    source_charge_layout_.push_back(negative_source);
}

void ElectricFieldApp::draw() {
    ci::Color background_color("black");
    ci::gl::clear(background_color);

    electric_field_.Display();

    for (Charge &charge : source_charge_layout_) {
        if (charge.get_charge_val() > 0) {
            ci::gl::color(ci::Color("red"));

        } else {
            ci::gl::color(ci::Color("cyan"));

        }
        ci::gl::drawStrokedCircle(charge.get_position(), electric_field_.get_charge_radius());
    }

    ci::gl::color(ci::Color("white"));
    ci::gl::drawString(initial_instructions, glm::vec2(kPositiveSource.x, kPositiveSource.y + kBelowSource));
}

std::vector<Arrow> ElectricFieldApp::GenerateArrowList() const {
    std::vector<Arrow> arrows;

    for (size_t i = 0; i < sqrt(kNumArrows); i++) {
        for (size_t j = 0; j < sqrt(kNumArrows); j++) {
            Arrow arrow(glm::vec2(kArrowMargin + j * (kArrowMargin / 2), kArrowMargin + i * (kArrowMargin / 2)));
            arrows.push_back(arrow);
        }
    }

    return arrows;
}

std::vector<Charge> ElectricFieldApp::GenerateChargeList() const {
    std::vector<Charge> charges;
    return charges;
}

void ElectricFieldApp::mouseDrag(cinder::app::MouseEvent event) {
    glm::vec2 mouse_loc = event.getPos();

    for (Charge &charge : electric_field_.get_charge_layout()) {
        //Check whether the user is clicking within an active charge
        bool drag_active_circle =
                (pow((mouse_loc.x - charge.get_position().x), 2) + pow((mouse_loc.y - charge.get_position().y), 2)) <=
                pow(electric_field_.get_charge_radius(), 2);

        if (drag_active_circle) {
            bool outside_x = mouse_loc.x <= electric_field_.get_first_corner().x ||
                             mouse_loc.x >= electric_field_.get_second_corner().x;
            bool outside_y = mouse_loc.y <= electric_field_.get_first_corner().y ||
                             mouse_loc.y >= electric_field_.get_second_corner().y;
            if (outside_x || outside_y) {

                electric_field_.RemoveCharge(charge);
                break;
            }
            charge.set_position(mouse_loc);
        }
    }
}

void ElectricFieldApp::mouseDown(cinder::app::MouseEvent event) {
    glm::vec2 mouse_loc = event.getPos();
    if (event.isLeft()) {

        for (Charge &charge: source_charge_layout_) {
            bool click_source_circle =
                    (pow((mouse_loc.x - charge.get_position().x), 2) +
                     pow((mouse_loc.y - charge.get_position().y), 2)) <=
                    pow(electric_field_.get_charge_radius(), 2);

            if (click_source_circle && !electric_field_.IsSpawnOccupied(charge.is_positive())) {
                if (charge.get_charge_val() > 0) {
                    Charge new_charge(electric_field_.get_positive_spawn(), charge.get_charge_val());
                    electric_field_.AddCharge(new_charge);

                } else {
                    Charge new_charge(electric_field_.get_negative_spawn(), charge.get_charge_val());
                    electric_field_.AddCharge(new_charge);
                }
            }
        }
    }
}

}  // namespace chargefield