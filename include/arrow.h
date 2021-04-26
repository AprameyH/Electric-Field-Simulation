#pragma once

#include <glm/vec2.hpp>

class Arrow {
private:
    glm::vec2 position_;
    const float kLength = 35;
    const float kTriangleWidth = 10;
    const float kTriangleHeight = 15;
    const float kPivot = 5;

public:
    const glm::vec2 &get_position() const;

    Arrow(const glm::vec2 &position);

    void DrawArrow(const glm::vec2 &direction);
};
