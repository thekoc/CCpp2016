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

void FlyingMachine::set_velocity(float x, float y) {
    velocity.x = x;
    velocity.y = y;
}

float FlyingMachine::speed() {
    return cal_module(velocity.x, velocity.y);
}

void FlyingMachine::set_velocity_direction(float x, float y) {
    float speed                = this->speed();
    sf::Vector2f unit_velocity = cal_unit(x, y);

    velocity = speed * unit_velocity;
}

void FlyingMachine::auto_move() {
    velocity += time_rate * accelerate;
    this->move(time_rate * velocity);
}
