#include "level1_scene.hpp"
#include "FlyingMachine.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

level1_scene::level1_scene(void) {}

state level1_scene::Run(sf::RenderWindow& App) {
    FlyingMachine player;
    sf::Texture   player_texture;

    player_texture.loadFromFile("player_plane.png");
    player.setTexture(player_texture);
    float move_speed = 10;

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
                    player.set_velocity(0, -1);
                    break;

                case sf::Keyboard::S:
                    player.set_velocity(0, 1);
                    break;

                case sf::Keyboard::A:
                    player.set_velocity(-1, 0);
                    break;

                case sf::Keyboard::D:
                    player.set_velocity(1, 0);
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
        player.auto_move();
        App.draw(player);

        // end the current frame
        App.display();
    }

    return state::stop;
}
