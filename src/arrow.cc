#include <cinder/gl/gl.h>
#include "arrow.h"

Arrow::Arrow(const glm::vec2 &position) : position_(position) {

}

void Arrow::DrawArrow(const glm::vec2 &direction) {
    //Drawing the line
    float angle = atan((direction.y - position_.y) / (direction.x - position_.x));

    float x_end = kLength * cos(angle) + position_.x;
    float y_end = kLength * sin(angle) + position_.y;

    float x_start = position_.x - kLength * cos(angle);
    float y_start = position_.y - kLength * sin(angle);

    glm::vec2 end_point(x_end, y_end);
    glm::vec2 start_point(x_start, y_start);

    ci::gl::drawLine(start_point, end_point);

    float line_length = distance(start_point, end_point);

    //Setting the head and tail of the arrow
    glm::vec2 arrow_head;
    glm::vec2 arrow_tail;
    if (distance(start_point, direction) < distance(end_point, direction)) {
        arrow_head = start_point;
        arrow_tail = end_point;
    } else if (distance(end_point, direction) < distance(start_point, direction)) {
        arrow_head = end_point;
        arrow_tail = start_point;
    }

    glm::vec2 unit_vec = (arrow_head - arrow_tail) / line_length;
    glm::vec2 switch_vec(-unit_vec.y, unit_vec.x);

    glm::vec2 first_corner = arrow_head - (kTriangleHeight * unit_vec) + (kTriangleWidth * switch_vec);
    glm::vec2 second_corner = arrow_head - (kTriangleHeight * unit_vec) - (kTriangleWidth * switch_vec);

    ci::gl::drawSolidTriangle(arrow_head,
                              first_corner, second_corner);
}

const glm::vec2 &Arrow::get_position() const {
    return position_;
}


