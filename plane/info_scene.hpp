#ifndef IMAGE_SCENE_HPP__
#define IMAGE_SCENE_HPP__

#include "Universe.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene.hpp"

class imag_scene : public scene {
private:

public:

    virtual state Run(sf::RenderWindow& App);
};

#endif // ifndef IMAGE_SCENE_HPP__
