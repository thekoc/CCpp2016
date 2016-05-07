#ifndef C_SCREEN_HPP__
#define C_SCREEN_HPP__


enum state { game, menu, stop };

#include <SFML/Graphics.hpp>
class scene {
public:

    float time_rate = 1;
    virtual state Run(sf::RenderWindow& App) = 0;
};

#endif // ifndef C_SCREEN_HPP__
