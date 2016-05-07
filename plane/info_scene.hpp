#ifndef IMAGE_SCENE_HPP__
#define IMAGE_SCENE_HPP__

#include "Universe.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cScreen.hpp"

class imag_scene : public cScreen {
private:

public:

    virtual state Run(sf::RenderWindow& App);
};

#endif // ifndef IMAGE_SCENE_HPP__
