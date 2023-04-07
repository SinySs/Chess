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
bool isMenuDraw = true;
bool isRulesDraw = false;
bool isCreditsDraw = false;
bool isTwoPlayersGameDraw = false;
bool isOnePlayerGameDraw = false;
bool isChooseColorDraw = false;
bool isFigureTake = false;

const int SCREEN_HEIGHT = 650, SCREEN_WIDTH = 650;

enum class figure_t
{
    PAWN, ROOK, HORSE, OFFICER, QUEEN, KING
};