#include <cinder/gl/gl.h>
#include "arrow.h"

Arrow::Arrow(const glm::vec2 &position) : position_(position) {

}

void Arrow::DrawArrow(const glm::vec2 &direction) {
    float angle = atan((direction.y - position_.y)/(direction.x - position_.x));

    float x_start;
    float y_start;

    float x_end = abs(kLength * cos(angle) + position_.x);
    float y_end = abs(kLength * sin(angle) + position_.y);

    glm::vec2 end_point(x_end,y_end);

    ci::gl::drawLine(position_, end_point);
}


