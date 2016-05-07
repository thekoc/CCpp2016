#ifndef UNIVERSE_HPP__
#define UNIVERSE_HPP__
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Universe {
private:

public:

    float time_rate;
    std::vector<Entity *> Entities;
    Universe(float time_rate) : time_rate(time_rate) {}

    void bind(Entity *entity);
};


#endif // ifndef UNIVERSE_HPP__
