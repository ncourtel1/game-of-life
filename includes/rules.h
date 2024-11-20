#ifndef RULES_H
#define RULES_H

#include <array>

const int WIN_HEIGHT = 480;  // Pas besoin de 'extern'
const int WIN_WIDTH = 640;   // Pas besoin de 'extern'

bool isAlive(std::array<std::array<int, WIN_HEIGHT>, WIN_WIDTH>& grid, const int x, const int y);

#endif