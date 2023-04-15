//
// Created by Дмитрий on 07.04.2023.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

bool isWhiteChoosen;
bool isComputerTurn;
bool is_menu_draw = true;
bool isRulesDraw = false;
bool is_game_end = false;
bool isTwoPlayersGameDraw = false;
bool isOnePlayerGameDraw = false;
bool is_choose_color_draw = false;
bool isFigureTake = false;

const int SCREEN_HEIGHT = 450, SCREEN_WIDTH = 450;

enum class figure_t
{
    PAWN, ROOK, HORSE, OFFICER, QUEEN, KING
};