#pragma once

#include <glm/vec2.hpp>

class Arrow {
private:
    glm::vec2 position_;
    const int kLength = 100;

public:
    Arrow(const glm::vec2 &position);

    void DrawArrow(const glm::vec2 &direction);
};
