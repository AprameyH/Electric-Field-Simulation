#include "arrow.h"

Arrow::Arrow(const glm::vec2 &position) : position_(position) {

}

void Arrow::DrawArrow(const glm::vec2 &direction) {
    ci::gl::drawLine(position_, direction);
}


