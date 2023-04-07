//
// Created by Дмитрий on 07.04.2023.
//

#pragma once
#include "game_settings.h"


class option
{
    sf::Text _text;
    sf::Font _font;
    int _text_size;

    enum class options
    {
        one_player,
        two_players,
        rules,
        back,
        white_side,
        black_side
    } _option;

public:
    option(std::string message, int x, int y, int option_n) {
        _font.loadFromFile("..\\data\\fonts\\arial.ttf");
        _text.setFont(_font);
        _text.setString(message);
        _text.setPosition(x, y);
        _text.setCharacterSize(70);
        _text.setFillColor(sf::Color::Black);
        _text_size = message.length();
        _option = options(option_n);
    }
    sf::Text get_text() {
        return _text;
    };


    void click_option(sf::RenderWindow &window) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2i range_pos;
        range_pos.x = _text.getPosition().x + _text.getCharacterSize() * (_text_size / 2);
        range_pos.y = _text.getPosition().y + _text.getCharacterSize();

        if(mouse_pos.x >= _text.getPosition().x && mouse_pos.x <= range_pos.x &&
           mouse_pos.y >= _text.getPosition().y && mouse_pos.y <= range_pos.y) {

            _text.setFillColor(sf::Color::Blue);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                switch (_option)
                {
                    case options::one_player:
                        isMenuDraw = false;
                        isChooseColorDraw = true;
                        break;
                    case options::two_players:
                        isMenuDraw = false;
                        isTwoPlayersGameDraw = true;
                        break;
                    case options::rules:
                        isMenuDraw = false;
                        isRulesDraw = true;
                        break;
                    case options::back:
                        isMenuDraw = true;
                        break;
                    case options::white_side:
                        isOnePlayerGameDraw = true;
                        isWhiteChoosen = true;
                        isComputerTurn = false;
                        break;
                    case options::black_side:
                        isOnePlayerGameDraw = true;
                        isWhiteChoosen = false;
                        isComputerTurn = true;
                        break;
                }
            }
        } else {
            _text.setFillColor(sf::Color::Black);
        }
    }
};


void menu(sf::RenderWindow &window)
{
    bool isRulesDraw = false;
    bool isCreditsDraw = false;
    bool isTwoPlayersGameDraw = false;
    bool isOnePlayerGameDraw = false;
    bool isChooseColorDraw = false;

    sf::RectangleShape background;
    sf::Texture background_texture;
    background_texture.loadFromFile("..\\images\\GameMenuBackground.jpg");
    background.setPosition(5, 5);
    background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    background.setTexture(&background_texture);


    option one_player("1 Player", 200, 120, 0);
    option two_players("2 Players", 200, 220, 1);
    option rules("Rules", 200, 320, 2);


    one_player.click_option(window);
    two_players.click_option(window);
    rules.click_option(window);

    window.clear();
    window.draw(background);
    window.draw(one_player.get_text());
    window.draw(two_players.get_text());
    window.draw(rules.get_text());
    window.display();

}