#ifndef ENTITY_HPP__
#define ENTITY_HPP__
#include <iostream>
#include <SFML/Graphics.hpp>

class Universe;

class Entity : public sf::Sprite {
private:

    /* data */

public:

    Universe *universe = NULL;
};

#endif // ifndef ENTITY_HPP__
