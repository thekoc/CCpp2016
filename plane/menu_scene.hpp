#ifndef MENU_SCENE_HPP__
#define MENU_SCENE_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene.hpp"

class menu_scene : public scene {
private:

public:

    bool muted = false;
    menu_scene(void);
    virtual state Run(sf::RenderWindow& App);
};

#endif // ifndef MENU_SCENE_HPP__
