//
// Created by Дмитрий on 14.04.2023.
//

#include "AssetManager.h"

asset_manager* asset_manager::instence = nullptr;

asset_manager::asset_manager() {
    assert(instence == nullptr);
    instence = this;
}

sf::Texture &asset_manager::get_texture(const std::string &filename) {
    auto &tex_map = instence->m_textures_;
    auto pair_found = tex_map.find(filename);

    if(pair_found != tex_map.end()) {
        return pair_found->second;
    } else {
        auto &texture = tex_map[filename];
        texture.loadFromFile(filename);
        return texture;
    }
}

sf::Font &asset_manager::get_font(const std::string &filename) {
    auto &font_map = instence->m_fonts_;
    auto pair_found = font_map.find(filename);

    if(pair_found != font_map.end()) {
        return pair_found->second;
    } else {
        auto &font = font_map[filename];
        font.loadFromFile(filename);
        return font;
    }
}
/*
sf::SoundBuffer &asset_manager::get_sound(const std::string &filename) {
    auto &sound_map = instence->m_sounds_;
    auto pair_sound = sound_map.find(filename);

    if(pair_sound != sound_map.end()) {
        return pair_sound->second;
    } else {
        auto &sound = sound_map[filename];
        sound.loadFromFile(filename);
        return sound;
    }
}*/