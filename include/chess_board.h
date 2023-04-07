//
// Created by Дмитрий on 07.04.2023.
//

#pragma once
#include "game_settings.h"
#include "figure.h"

class chess_board
{
    sf::RectangleShape _board, _cells[64];
    sf::Texture _board_texture, _cell_texture;

    bool is_figure_choosen = false, is_my_turn = false;

    void FigureMovement(figure_t &type, sf::RectangleShape &fig, std::string &position,
                        std::vector<figure> &enemyFigure, std::vector<figure> &friendFigure);
public:
    int *fig_index;  //unicpointer
    std::string fig_color;

    chess_board() {
        fig_color = "black";

        _board_texture.loadFromFile("..\\images\\board0.png");
        _board.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
        _board.setPosition(5, 5);
        _board.setTexture(&_board_texture);

        _cell_texture.loadFromFile("..\\images\\GridCell.png");
        for (int i = 0; i < 64; i++)
        {
            _cells[i].setSize(sf::Vector2f(66, 66));
            _cells[i].setTexture(&_cell_texture);
        }
    }
    ~chess_board() {
        delete fig_index;
    }

    void take_figure(sf::RenderWindow &window, sf::RectangleShape &fig, figure_t &type,
                    std::string &position, std::vector<figure> &enemy_figure, std::vector<figure> &friend_figure,
                    int i, std::string color);

    void place_figure(sf::RenderWindow &window, std::vector<figure> &enemy_figure,
                      std::vector<figure> &friend_figure);

    void set_positions(std::vector<figure> &fig, int start, int end, int pos);
    void game_end(sf::RenderWindow &window, std::vector<figure> &black_figure,
                  std::vector<figure> &white_figure); ///MAKE SHORTER

    void draw_cells(sf::RenderWindow &window) {
        for(int i = 0; i < 64; i++)
        {
            window.draw(_cells[i]);
        }
    }
};

void chess_board::set_positions(std::vector<figure> &figs, int start, int end, int pos) {
    if(pos == 1) {
        for(int i = start, j = 0; i < end; ++i, ++j) {
            figs[j].set_position(_cells[i].getPosition().x, _cells[i].getPosition().y);
        }
    } else {
        for(int i = start, j = 15; i < end; ++i, --j) {
            figs[j].set_position(_cells[i].getPosition().x, _cells[i].getPosition().y);
        }
    }
}


