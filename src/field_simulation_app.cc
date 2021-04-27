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

        for (size_t i = 0; i < sqrt(kNumArrows); i++) {
            for (size_t j = 0; j < sqrt(kNumArrows); j++) {
                Arrow arrow(glm::vec2(kArrowMargin + j * (kArrowMargin / 2), kArrowMargin + i * (kArrowMargin / 2)));
                arrows.push_back(arrow);
            }
        }
//        Arrow arrow(glm::vec2(200,600));
//                arrows.push_back(arrow);

        return arrows;
    }

    std::vector<Charge> ElectricFieldApp::GenerateChargeList() const {
        std::vector<Charge> charges;
        Charge charge_one(glm::vec2(400, 400), 1);
        charges.push_back(charge_one);
//        Charge charge_two(glm::vec2(500, 400), -1);
//        charges.push_back(charge_two);
        return charges;
    }

}  // namespace chargefield