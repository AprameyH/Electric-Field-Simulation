#pragma once

#include <glm/vec2.hpp>

class Arrow {
public:
    const glm::vec2 &get_position() const;

    Arrow(const glm::vec2 &position);

    /**
     * Draws an arrow of fixed length.
     * @param direction in which the arrow will be drawn.
     */
    void DrawArrow(const glm::vec2 &direction) const;

private:
    glm::vec2 position_;

    const float kLength = 21;
    const float kTriangleWidth = 6;
    const float kTriangleHeight = 9;
    /**
     * The radius of the pivot circle.
     */
    const float kPivot = 3;
};
