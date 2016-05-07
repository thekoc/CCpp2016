#include "level1_scene.hpp"
#include "FlyingMachine.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

level1_scene::level1_scene(void) {}

state level1_scene::Run(sf::RenderWindow& App) {
    Universe universe(1);

    FlyingMachine player(&universe);
    sf::Texture   player_texture;

    player_texture.loadFromFile("player_plane.png");
    player.setTexture(player_texture);

    while (App.isOpen())
    {
        universe.update_bullet_time_mode();
        sf::Event Event;

        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return state::stop;
            }

            if (Event.KeyPressed) {
                switch (Event.key.code) {
                case sf::Keyboard::L:
                    universe.bullet_time_on();
                    break;

                default:
                    break;
                }
            }
        }

        // key event
        float speed = 10;
        sf::Vector2f v;
        sf::Keyboard::Key latest_key;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            v.y       -= speed;
            latest_key = sf::Keyboard::W;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            v.y       += speed;
            latest_key = sf::Keyboard::S;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            v.x       -= speed;
            latest_key = sf::Keyboard::A;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            v.x       += speed;
            latest_key = sf::Keyboard::D;
        }


        player.set_velocity(v);

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
