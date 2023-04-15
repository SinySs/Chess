//
// Created by Дмитрий on 14.04.2023.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "game_settings.h"
#include "AssetManager.h"
#include "menu.h"

class Engen{
    asset_manager manager;
    std::unique_ptr<sf::RenderWindow> window_;
    void input();
    void update(sf::Time const &dT);

    sf::RectangleShape background_ = sf::RectangleShape(sf::Vector2f(450, 450));

public:
    Engen();
    void run();

};

void Engen::input() {
    sf::Event event;
    main_menu M;
    while (window_->pollEvent(event))
    {
        if(event.key.code == sf::Keyboard::Escape)
            window_->close();

        if (event.type == sf::Event::Closed)
            window_->close();

        if(is_game_end) {
            window_->close();
        }

        if(is_menu_draw)
            M.draw(*window_);


    }

}

void Engen::run() {

    sf::Clock clock;

    while (window_->isOpen()) {
        sf::Time dt = clock.restart();

        input();
        update(dt);
    }

}

void Engen::update(const sf::Time &dT) {

}

Engen::Engen() {
    window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH), "Chess!");
}
