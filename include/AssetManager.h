//
// Created by Дмитрий on 14.04.2023.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <cassert>
#include <iostream>

class asset_manager
{
    std::map<std::string, sf::Texture> m_textures_;
    std::map<std::string, sf::Font> m_fonts_;

    static asset_manager *instence;

public:

    asset_manager();

    static sf::Texture &get_texture(std::string const &filename);
    static sf::Font &get_font(std::string const &filename);

};