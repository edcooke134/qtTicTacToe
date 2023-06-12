//
// Created by edc on 12.06.23.
//

#ifndef TICTACTOE_MINIMAX_H
#define TICTACTOE_MINIMAX_H

#include "boardConfig.h"
#include <algorithm>

class Minimax {
public:
    int findBestMove(Position position);

private:
    int evaluate(const Position &position);

    int minimax(Position position, int player);
};

#endif //TICTACTOE_MINIMAX_H
