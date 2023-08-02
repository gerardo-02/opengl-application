#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "object3d.h"
#include <QString>

class _chess_board:public _object3D
{
public:
    _chess_board(float SizeX = 1.0, float SizeY = 1.0);
};

#endif // CHESS_BOARD_H
