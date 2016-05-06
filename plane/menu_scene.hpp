#ifndef MENU_SCENE_HPP__
#define MENU_SCENE_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "cScreen.hpp"

class menu_scene : public cScreen {
private:

public:

    menu_scene(void);
    virtual state Run(sf::RenderWindow& App);
};

#endif // ifndef MENU_SCENE_HPP__
