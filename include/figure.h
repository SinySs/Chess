//
// Created by Дмитрий on 07.04.2023.
//
#pragma once

#include "game_settings.h"

class figure{
    sf::RectangleShape _figure;
    sf::Texture _texture;
    figure_t _type;

public:
    figure(figure_t type, std::string path) : _type(type) {
        _texture.loadFromFile(path);
        _figure.setTexture(&_texture);
        _figure.setSize(sf::Vector2f(66, 66));

    }

    figure_t& get_type() {
        return _type;
    }

    void set_position(double x, double y) {
        _figure.setPosition(x, y);
    }

    sf::RectangleShape& get_share() {
        return _figure;
    }

};
