#ifndef UNIVERSE_HPP__
#define UNIVERSE_HPP__
#include <iostream>
#include <SFML/Graphics.hpp>

class Universe {
private:

public:

    float time_rate;
    std::vector<sf::Sprite *> Sprites;
    Universe(float time_rate) : time_rate(time_rate) {}

    virtual ~Universe();
};


#endif // ifndef UNIVERSE_HPP__
