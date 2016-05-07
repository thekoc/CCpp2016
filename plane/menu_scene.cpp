#include "menu_scene.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

menu_scene::menu_scene(void) {}

state menu_scene::Run(sf::RenderWindow& App) {
    sf::Font Font;

    if (!Font.loadFromFile("verdanab.ttf")) {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return state::stop;
    }
    sf::Text Menu1;
    Menu1.setFont(Font);
    Menu1.setCharacterSize(20);
    Menu1.setString("menu");
    Menu1.setPosition(sf::Vector2f(280.f, 160.f));


    while (App.isOpen())
    {
        sf::Event Event;

        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return state::stop;
            }

            // Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Return:
                    return state::level1;

                default:
                    break;
                }
            }
        }

        // clear the App with black color
        App.clear();

        // App.draw(...);
        App.draw(Menu1);

        // end the current frame
        App.display();
    }

    return state::stop;
}