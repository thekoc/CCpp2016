#ifndef C_SCREEN_HPP__
#define C_SCREEN_HPP__


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum state { game, menu, stop };

class scene {
public:

    sf::Sound *BGM;
    float time_rate = 1;
    virtual state Run(sf::RenderWindow& App) = 0;
};

#endif // ifndef C_SCREEN_HPP__
