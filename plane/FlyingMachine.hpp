#ifndef FLYING_MACHINE_HPP__
#define FLYING_MACHINE_HPP__
#include "Universe.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class FlyingMachine : public sf::Sprite {
private:

public:

    FlyingMachine();
    Universe *universe = NULL;
    FlyingMachine(Universe *universe);
    float time_rate = 1;
    void  set_velocity_direction(float x,
                                 float y);
    void  set_velocity(float x,
                       float y);
    float speed();
    sf::Vector2f velocity   = sf::Vector2f(0, 0);
    sf::Vector2f accelerate = sf::Vector2f(0, 0);
    void  auto_move();
};


#endif // ifndef FLYING_MACHINE_HPP__
