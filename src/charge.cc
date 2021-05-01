#include "charge.h"

Charge::Charge(const glm::vec2 &position, double charge_val) : position_(position), charge_val_(charge_val) {
}

bool Charge::is_positive() const {
    return charge_val_ >= 0;
}

const glm::vec2 &Charge::get_position() const {
    return position_;
}

double Charge::get_charge_val() const {
    return charge_val_;
}

void Charge::set_position(const glm::vec2 &position) {
    position_ = position;
}

bool operator==(Charge &one, Charge &two) {
    return one.position_ == two.position_ && one.charge_val_ == two.charge_val_;
}

