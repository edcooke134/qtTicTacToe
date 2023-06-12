//
// Created by edc on 10.06.23.
//

#ifndef TICTACTOE_BASEOPPONENT_H
#define TICTACTOE_BASEOPPONENT_H

#include "boardConfig.h"

class BaseOpponent {
public:
    virtual Position getNextMove(const Position &, bool hardMode) = 0;

    virtual ~BaseOpponent() = default;
};

#endif //TICTACTOE_BASEOPPONENT_H
