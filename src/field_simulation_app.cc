#include "field_simulation_app.h"

namespace chargefield{

    ElectricField(GenerateArrowList()) {
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
        glm::vec2 start(100, 100);
        for (size_t i = 0; i < 7; i++) {
            for (size_t j = 0; j < 7; j++) {
                Arrow arrow(glm::vec2(start.x + 25, start.y));
            }
            start.y = start.y + 25;
        }
        return std::vector<Arrow>();
    }

}  // namespace chargefield