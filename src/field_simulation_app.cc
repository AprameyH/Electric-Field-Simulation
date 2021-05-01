#include <cinder/gl/wrapper.h>
#include <cinder/gl/draw.h>
#include "field_simulation_app.h"
#include "cinder/app/App.h"


namespace chargefield {

ElectricFieldApp::ElectricFieldApp() : electric_field_(GenerateArrowList(), GenerateChargeList()) {
    ci::app::setWindowSize(kWindowSize, kMargin);
}

void ElectricFieldApp::draw() {
    ci::Color background_color("black");
    ci::gl::clear(background_color);

    electric_field_.Display();

    ci::gl::color(ci::Color("cyan"));
    ci::gl::drawStrokedCircle(kNegativeSource, electric_field_.get_charge_radius());

    ci::gl::color(ci::Color("red"));
    ci::gl::drawStrokedCircle(kPositiveSource, electric_field_.get_charge_radius());

    ci::gl::color(ci::Color("white"));
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
    Charge charge_one(glm::vec2(600, 450), -1);
    charges.push_back(charge_one);
    Charge charge_two(glm::vec2(300, 450), 1);
    charges.push_back(charge_two);
    return charges;
}

void ElectricFieldApp::mouseDrag(cinder::app::MouseEvent event) {
    glm::vec2 mouse_loc = event.getPos();

    for (Charge &charge : electric_field_.get_charge_layout()) {
        //Check whether the user is clicking within the circle
        bool drag_within_circle =
                (pow((mouse_loc.x - charge.get_position().x), 2) + pow((mouse_loc.y - charge.get_position().y), 2)) <=
                pow(electric_field_.get_charge_radius(), 2);
        if (drag_within_circle) {
            if (mouse_loc.x <= electric_field_.get_first_corner().x
                || mouse_loc.y <= electric_field_.get_first_corner().y
                || mouse_loc.x >= electric_field_.get_second_corner().x
                || mouse_loc.y >= electric_field_.get_second_corner().y) {
                electric_field_.RemoveCharge(charge);
            }
            charge.set_position(mouse_loc);
        }
    }
}

}  // namespace chargefield