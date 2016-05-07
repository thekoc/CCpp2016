#ifndef FLYING_MACHINE_HPP__
#define FLYING_MACHINE_HPP__

#include "Universe.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class FlyingMachine : public sf::Sprite {
private:

    sf::Vector2f velocity = sf::Vector2f(0, 0);

public:

    FlyingMachine();
    FlyingMachine(Universe *universe);
    Universe *universe = NULL;

    float time_rate = 1;

    void  set_velocity_direction(float x,
                                 float y);
    void  set_velocity(float x,
                       float y);
    void  set_velocity(sf::Vector2f new_v);

    float speed() const;

    sf::Vector2f accelerate = sf::Vector2f(0, 0);
    void  set_accelerate(float x,
                         float y);
    void  set_accelerate(sf::Vector2f na);

    void  auto_move();
    float max_speed = 5;
};


#endif // ifndef FLYING_MACHINE_HPP__
