//
// Created by edc on 10.06.23.
//

#ifndef TICTACTOE_EASYOPPONENT_H
#define TICTACTOE_EASYOPPONENT_H

#include "baseOpponent.h"

// A class to implement
class OpponentImpl : public BaseOpponent {
public:
    Position getNextMove(const Position &, bool hardMode) override;

private:
    Position getNextEasyMove(const Position &) const;

    Position getNextHardMove(const Position &) const;
};

#endif //TICTACTOE_EASYOPPONENT_H
