#include "menu_scene.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

menu_scene::menu_scene(void) {}

void set_center(std::vector<sf::Text *>menus, sf::RenderWindow& App) {
    float height      = App.getSize().y;
    float width       = App.getSize().x;
    float total_heigh = 0;

    for (auto menu : menus)
    {
        menu->setCharacterSize(height / (menus.size() * 3));
        total_heigh += menu->getGlobalBounds().height;
    }
    float spacey       = (height - total_heigh) / (menus.size() + 1);
    float relative_top = 0;

    for (auto menu: menus) {
        float menu_width  = menu->getGlobalBounds().width;
        float menu_height = menu->getGlobalBounds().height;
        relative_top += spacey;
        float spacex = (width - menu_width) / 2;
        menu->setPosition(spacex, relative_top);
        relative_top += menu_height;
    }
}

void config_text(sf::Text *text, sf::String content,
                 std::vector<sf::Text *>& menus,
                 sf::Font& font) {
    menus.push_back(text);

    text->setFont(font);
    text->setString(content);
}

state menu_scene::Run(sf::RenderWindow& App) {
    sf::Font Font;

    if (!Font.loadFromFile("verdanab.ttf")) {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return state::stop;
    }

    std::vector<sf::Text *> menus;

    sf::Text continue_menu;
    sf::Text mute_menu;
    sf::Text exit_menu;

    config_text(&continue_menu, L"继续", menus, Font);
    config_text(&mute_menu,     L"静音", menus, Font);
    config_text(&exit_menu,     L"退出", menus, Font);

    set_center(menus, App);


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
        for (auto menu : menus) {
            App.draw(*menu);
        }

        // end the current frame
        App.display();
    }

    return state::stop;
}
