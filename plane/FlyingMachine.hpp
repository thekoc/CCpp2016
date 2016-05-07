#ifndef FLYING_MACHINE_HPP__
#define FLYING_MACHINE_HPP__

#include "Universe.hpp"
#include "Entity.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class FlyingMachine : public Entity {
private:

    sf::Vector2f velocity = sf::Vector2f(0, 0);
    float __time_rate     = 0;

public:

    FlyingMachine(Universe *universe);
    float get_time_rate() const;

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
