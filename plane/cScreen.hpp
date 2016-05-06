#ifndef C_SCREEN_HPP__
#define C_SCREEN_HPP__


enum state { level1, menu, stop };

#include <SFML/Graphics.hpp>
class cScreen {
public:

    virtual state Run(sf::RenderWindow& App) = 0;
};

#endif // ifndef C_SCREEN_HPP__
