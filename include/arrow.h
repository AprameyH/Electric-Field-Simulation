#pragma once

#include <glm/vec2.hpp>
#include "gas_container.h"

class Arrow {
private:
    glm::vec2 position_;


public:
    Arrow(const glm::vec2 &position);

    void DrawArrow(const glm::vec2 &direction);
};
