#include "charge.h"

Charge::Charge(bool is_positive, const glm::vec2 &position, double charge_val) : is_positive_(is_positive), position_(position), charge_val_(charge_val) {
}

bool Charge::is_positive() const {
    return is_positive_;
}

const glm::vec2 &Charge::get_position() const {
    return position_;
}

double Charge::get_charge_val() const {
    return charge_val_;
}
