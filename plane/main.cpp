#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "screens.hpp"

int main() {
    // Applications variables
    std::map<state, scene *> scenes;

    // Window creation
    sf::RenderWindow App(sf::VideoMode(1200, 800), "The Trueman Show");

    App.clear();

    App.setFramerateLimit(60);

    // Mouse cursor no more visible
    // App.setMouseCursorVisible(false);

    // Screens preparations
    state screen = state::menu;
    menu_scene   ms;
    level1_scene scene1;
    scenes[state::menu] = &ms;
    scenes[state::game] = &scene1;

    // Main loop
    while (screen != state::stop) {
        screen = scenes[screen]->Run(App);
    }

    return EXIT_SUCCESS;
}
