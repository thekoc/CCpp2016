#include "level1_scene.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

level1_scene::level1_scene(void) {}

state level1_scene::Run(sf::RenderWindow& App) {
    // sf::Font Font;
    //
    // if (!Font.loadFromFile("verdanab.ttf")) {
    //     std::cerr << "Error loading verdanab.ttf" << std::endl;
    //     return state::stop;
    // }
    // sf::Text Menu1;
    // Menu1.setFont(Font);
    // Menu1.setCharacterSize(20);
    // Menu1.setString("play");
    // Menu1.setPosition(sf::Vector2f(280.f, 160.f));

    sf::Sprite  player;
    sf::Texture player_texture;

    player_texture.loadFromFile("player_plane.png");
    player.setTexture(player_texture);
    double move_speed = 10;

    // run the program as long as the App is open
    while (App.isOpen())
    {
        // check all the App's events that were triggered since the last
        // iteration of the loop
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
                case sf::Keyboard::W:
                    player.move(0, -time_rate * move_speed);
                    break;

                case sf::Keyboard::S:
                    player.move(0, time_rate * move_speed);
                    break;

                case sf::Keyboard::A:
                    player.move(-1 * time_rate * move_speed, 0);
                    break;

                case sf::Keyboard::D:
                    player.move(time_rate * move_speed, 0);
                    break;

                default:
                    break;
                }
            }
        }

        // clear the App with black color
        App.clear();

        // draw everything here...
        // App.draw(...);
        App.draw(player);

        // end the current frame
        App.display();
    }

    return state::stop;
}
