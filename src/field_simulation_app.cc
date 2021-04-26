#include <cinder/gl/wrapper.h>
#include "field_simulation_app.h"

namespace chargefield {

    ElectricFieldApp::ElectricFieldApp() : electric_field_(GenerateArrowList(), GenerateChargeList()) {
        ci::app::setWindowSize(kWindowSize, kMargin);
    }

    void ElectricFieldApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);

        electric_field_.Display();
    }

    void ElectricFieldApp::update() {
        electric_field_.AdvanceOneFrame();
    }

    std::vector<Arrow> ElectricFieldApp::GenerateArrowList() const {
        std::vector<Arrow> arrows;

        for (size_t i = 0; i < 6; i++) {
            for (size_t j = 0; j < 6; j++) {
                Arrow arrow(glm::vec2(kArrowMargin + j * (kArrowMargin / 2), kArrowMargin + i * (kArrowMargin / 2)));
                arrows.push_back(arrow);
            }
        }
        return arrows;
    }

    std::vector<Charge> ElectricFieldApp::GenerateChargeList() const {
        std::vector<Charge> charges;
        Charge charge_one(false, glm::vec2(300, 300), 8 * pow(10, -9));
        charges.push_back(charge_one);
        return charges;
    }

}  // namespace chargefield