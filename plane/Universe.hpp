#ifndef UNIVERSE_HPP__
#define UNIVERSE_HPP__
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class FlyingMachine;
class Universe {
private:

    sf::Clock clock;
    bool      bullet_time = false;
    float     bullet_time_duration;

public:

    FlyingMachine *player;
    float time_rate;
    std::vector<Entity *> Entities;

    Universe(float time_rate) : time_rate(time_rate) {}

    void bullet_time_on(float duration = -1);
    void update_bullet_time_mode();
    void bind(Entity *entity);
    virtual ~Universe();
};


#endif // ifndef UNIVERSE_HPP__
