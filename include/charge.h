#pragma once

#include <glm/vec2.hpp>

class Charge {
private:
    glm::vec2 position_;
    double charge_val_;

public:
    Charge(const glm::vec2 &position, double charge_val);

    bool is_positive() const;

    const glm::vec2 &get_position() const;

    double get_charge_val() const;
};

