#ifndef LEVELE1_SCENE_HPP__
#define LEVELE1_SCENE_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Universe.hpp"
#include "scene.hpp"

class level1_scene : public scene {
private:

public:

    Universe universe = Universe(1);
    level1_scene(void);
    virtual state Run(sf::RenderWindow& App);
};


#endif // ifndef LEVELE1_SCENE_HPP__
