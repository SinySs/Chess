//
// Created by Дмитрий on 07.04.2023.
//

#pragma once
#include "game_settings.h"
#include "AssetManager.h"
#include <vector>
#include <string>

#define OPTIONS_N 3

std::string background_file = {"../img/board0.png"};
std::vector<std::string> files = {"../img/1111.png", "../img/222.png", "../img/333.png"};
std::vector<std::pair<float, float>> pos = {std::make_pair(100, 30),
                                            std::make_pair(100, 90),
                                            std::make_pair(100, 150)};

class main_menu
{
    sf::Sprite options_[OPTIONS_N];
    sf::Sprite bg_;
    int menu_num_;
    int check_option(sf::RenderWindow &window);
    void select_option();

    enum  options
    {
        one_player = 0,
        two_players = 1,
        back = 2,
        white_side,
        black_side
    };

public:
    main_menu();
    void draw(sf::RenderWindow & window);
};

main_menu::main_menu() {
    for(int i = 0; i < OPTIONS_N; ++i) {
        options_[i].setTexture(asset_manager::get_texture(files[i]));
        options_[i].setPosition(pos[i].first, pos[i].second);
    }

    bg_.setTexture(asset_manager::get_texture(background_file));
    bg_.setPosition(282, 0);
    menu_num_ = 0;

}

void main_menu::draw(sf::RenderWindow &window) {
    while (is_menu_draw) {
        for(int i = 0; i < OPTIONS_N; ++i) {
            options_[i].setColor(sf::Color::White);
        }
        menu_num_ = 0;
        window.clear(sf::Color(129, 181, 221));

        menu_num_ = check_option(window);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {window.close(); is_menu_draw = false; }
        if(is_game_end) {window.close();}

        window.draw(bg_);

        for(int i = 0; i < OPTIONS_N; ++i) {
            window.draw(options_[i]);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            select_option();


        window.display();
    }
}

int main_menu::check_option(sf::RenderWindow &window) {
    for(int i = 0; i < OPTIONS_N; ++i) {
        if(sf::IntRect(pos[i].first, pos[i].second, 300, 50).contains(sf::Mouse::getPosition(window))) {
            options_[i].setColor(sf::Color::Blue);
            return i;
        }
    }
}

void main_menu::select_option() {

    switch (menu_num_) {
        case options::one_player:
            is_menu_draw = false;
            is_choose_color_draw = true;
            break;

        case options::two_players:
            is_menu_draw = false;
            isTwoPlayersGameDraw = true;
            break;

        case options::back:
            is_game_end = true;
            break;
    }
}
