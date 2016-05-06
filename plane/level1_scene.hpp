#ifndef LEVELE1_SCENE_HPP__
#define LEVELE1_SCENE_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "cScreen.hpp"

class level1_scene : public cScreen {
private:

public:

    level1_scene(void);
    virtual state Run(sf::RenderWindow& App);
};


#endif // ifndef LEVELE1_SCENE_HPP__
