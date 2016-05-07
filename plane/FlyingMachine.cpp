#include "FlyingMachine.hpp"
#include "Universe.hpp"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

FlyingMachine::FlyingMachine(Universe *universe) {
    this->universe = universe;
    time_rate      = universe->time_rate;
}

FlyingMachine::FlyingMachine() {}

float cal_module(float x, float y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

sf::Vector2f cal_unit(float x, float y) {
    float module = cal_module(x, y);
    float ux     = x / module;
    float uy     = y / module;

    return sf::Vector2f(ux, uy);
}

void FlyingMachine::set_velocity(sf::Vector2f new_v) {
    set_velocity(new_v.x, new_v.y);
}

void FlyingMachine::set_velocity(float x, float y) {
    if (cal_module(x, y) > max_speed) {
        velocity = max_speed * cal_unit(x, y);
    } else {
        velocity = sf::Vector2f(x, y);
    }
}

float FlyingMachine::speed() const {
    return cal_module(velocity.x, velocity.y);
}

void FlyingMachine::set_velocity_direction(float x, float y) {
    float speed                = this->speed();
    sf::Vector2f unit_velocity = cal_unit(x, y);

    set_velocity(speed * unit_velocity);
}

void FlyingMachine::set_accelerate(sf::Vector2f na) {
    set_accelerate(na.x, na.y);
}

void FlyingMachine::set_accelerate(float x, float y) {
    accelerate = sf::Vector2f(x, y);
}

void FlyingMachine::auto_move() {
    set_velocity(velocity + time_rate * accelerate);
    this->move(time_rate * velocity);
}
