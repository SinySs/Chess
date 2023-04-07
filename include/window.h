//
// Created by Дмитрий on 07.04.2023.
//

#pragma once
#include <SFML/Graphics.hpp>

#include "chess_board.h"
#include "menu.h"


std::vector<figure> take_figure()
{
    std::vector<figure> figs;
    figs.push_back(figure( figure_t::ROOK, "..\\images\\WhiteRook.png"));
    figs.push_back(figure( figure_t::HORSE, "..\\images\\WhiteHorse.png"));
    figs.push_back(figure( figure_t::OFFICER, "..\\images\\WhiteOfficer.png"));
    figs.push_back(figure( figure_t::KING, "..\\images\\WhiteKing.png"));
    figs.push_back(figure( figure_t::QUEEN, "..\\images\\WhiteQueen.png"));
    figs.push_back(figure( figure_t::OFFICER, "..\\images\\WhiteOfficer.png"));
    figs.push_back(figure( figure_t::HORSE, "..\\images\\WhiteHorse.png"));
    figs.push_back(figure( figure_t::ROOK, "..\\images\\WhiteRook.png"));

    for(int i = 0; i < 8; ++i)
        figs.push_back(figure( figure_t::PAWN, "..\\images\\WhitePawn.png"));

    return  figs;

}

namespace chess{

    void run() {
        sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chess!");
        chess_board my_chess;

        std::vector<figure> white_figs = take_figure();
        std::vector<figure> black_figs = take_figure();

        my_chess.set_positions(black_figs, 0, 16, 1);
        my_chess.set_positions(white_figs, 48, 64, 2);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            if (isMenuDraw == true)
            {
                menu(window);
            }
        }
    }
}

