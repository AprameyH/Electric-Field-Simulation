#include <cinder/gl/wrapper.h>
#include "field_simulation_app.h"

namespace chargefield{

    ElectricFieldApp::ElectricFieldApp() : electric_field_(GenerateArrowList()){
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
        glm::vec2 start(100, 100);
        Arrow arrow1(glm::vec2(150,150));
        arrows.push_back(arrow1);
        Arrow arrow2(glm::vec2(750,750));
        arrows.push_back(arrow2);
        Arrow arrow3(glm::vec2(750,150));
        arrows.push_back(arrow3);
        Arrow arrow4(glm::vec2(150,750));
        arrows.push_back(arrow4);
        Arrow arrow5(glm::vec2(400,150));
        arrows.push_back(arrow5);
        return arrows;
    }

}  // namespace chargefield