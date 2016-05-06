#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "screens.hpp"

int main()
{
    // Applications variables
    std::map<state, cScreen *> Screens;

    // Window creation
    sf::RenderWindow App(sf::VideoMode(640, 480), "The Trueman Show");

    // Mouse cursor no more visible
    App.setMouseCursorVisible(false);

    // Screens preparations
    state screen = state::menu;
    menu_scene   ms;
    level1_scene scene1;
    Screens[state::menu]   = &ms;
    Screens[state::level1] = &scene1;

    // Main loop
    while (screen != state::stop)
    {
        screen = Screens[screen]->Run(App);
    }

    return EXIT_SUCCESS;
}
