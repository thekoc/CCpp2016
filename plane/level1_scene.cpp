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
        bool key_pressed = false;

        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return state::stop;
            }

            // // Key pressed
            // if (Event.type == sf::Event::KeyPressed)
            // {
            //     key_pressed = true;
            //
            //     switch (Event.key.code)
            //     {
            //     case sf::Keyboard::W:
            //         std::cout << "W" << std::endl;
            //         player.set_accelerate(0, -0.05);
            //         break;
            //
            //     case sf::Keyboard::S:
            //         std::cout << "S" << std::endl;
            //         player.set_accelerate(0, 0.05);
            //         break;
            //
            //     case sf::Keyboard::A:
            //         std::cout << "A" << std::endl;
            //         player.set_accelerate(-0.05, 0);
            //         break;
            //
            //     case sf::Keyboard::D:
            //         std::cout << "D" << std::endl;
            //         player.set_accelerate(0.05, 0);
            //         break;
            //
            //     default:
            //         break;
            //     }
            // }
            //
            // if (!key_pressed) {
            //     player.set_accelerate(0, 0);
            // }
        }

        // key event
        float speed = 1;
        sf::Vector2f v;
        sf::Keyboard::Key latest_key;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { v.y       -= speed;
                                                           latest_key =
                                                               sf::Keyboard::W; }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { v.y       += speed;
                                                           latest_key =
                                                               sf::Keyboard::S; }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { v.x       -= speed;
                                                           latest_key =
                                                               sf::Keyboard::A; }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { v.x       += speed;
                                                           latest_key =
                                                               sf::Keyboard::D; }
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
