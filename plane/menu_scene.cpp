#include "menu_scene.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

menu_scene::menu_scene(void) {}

void set_center(std::vector<sf::Text *>menus, sf::RenderWindow& App) {
    float height      = App.getSize().y;
    float width       = App.getSize().x;
    float total_heigh = 0;

    for (auto menu : menus) {
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
    text->setColor(sf::Color::White);
    text->setFont(font);
    text->setString(content);
}

void enable_sound(std::vector<sf::Text *>& menus,
                  sf::Text               & mute_menu,
                  sf::RenderWindow       & App,
                  bool                   & muted,
                  menu_scene             & ms) {
    ms.BGM->setVolume(100);
    muted = false;
    mute_menu.setString(L"静音");
    set_center(menus, App);
}

void disable_sound(std::vector<sf::Text *>& menus,
                   sf::Text               & mute_menu,
                   sf::RenderWindow       & App,
                   bool                   & muted,
                   menu_scene             & ms) {
    ms.BGM->setVolume(0);
    muted = true;
    mute_menu.setString(L"恢复声音");
    set_center(menus, App);
}

state menu_scene::Run(sf::RenderWindow& App) {
    sf::Font Font;

    if (!Font.loadFromFile("verdanab.ttf")) {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return state::stop;
    }

    std::vector<sf::Text *> menus;

    sf::Text   continue_menu;
    sf::Text   mute_menu;
    sf::Text   exit_menu;
    sf::String mute_string = muted ? L"恢复声音" : L"静音";
    config_text(&continue_menu, L"继续",       menus, Font);
    config_text(&mute_menu,     mute_string, menus, Font);
    config_text(&exit_menu,     L"退出",       menus, Font);

    int current_menu = 0;

    set_center(menus, App);


    while (App.isOpen()) {
        sf::Event Event;

        while (App.pollEvent(Event)) {
            // Window closed
            if (Event.type == sf::Event::Closed) {
                return state::stop;
            }

            // Key pressed
            if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                case sf::Keyboard::W:

                    if (current_menu > 0) {
                        current_menu--;
                    }
                    break;

                case sf::Keyboard::S:

                    if (current_menu < menus.size() - 1) {
                        current_menu++;
                    }
                    break;

                case sf::Keyboard::Return:

                    if (current_menu == 0) {
                        return state::game;
                    } else if (current_menu == 1) {
                        if (muted) {
                            enable_sound(menus, mute_menu, App, muted, *this);
                        } else {
                            disable_sound(menus, mute_menu, App, muted, *this);
                        }
                    } else if (current_menu == 2) {
                        return state::stop;
                    }
                    break;

                default:
                    break;
                }
            }
        }

        // clear the App with black color
        App.clear();

        // App.draw(...);
        for (auto menu: menus) {
            menu->setColor(sf::Color::White);
        }
        menus[current_menu]->setColor(sf::Color::Red);

        for (auto menu : menus) {
            App.draw(*menu);
        }

        // end the current frame
        App.display();
    }

    return state::stop;
}
