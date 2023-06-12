//
// Created by edc on 10.06.23.
//
#include "opponentImpl.h"
#include "minimax.h"
#include <ctime>

Position OpponentImpl::getNextMove(const Position &position, bool hardMode) {
    return hardMode ? getNextHardMove(position) : getNextEasyMove(position);
}

Position OpponentImpl::getNextEasyMove(const Position &position) const {
    std::vector<size_t> free;
    Position ret = position;
    for (int idx = 0; idx < 9; ++idx) {
        if (position[idx] == TileState::None) {
            free.push_back(idx);
        }
    }
    if (!free.empty()) {
        const size_t randIdx = time(nullptr) % free.size();
        if (randIdx < free.size() && free[randIdx] < position.size()) {
            ret[free[randIdx]] = TileState::O;
        }
        return ret;
    }
    return position;
}

Position OpponentImpl::getNextHardMove(const Position &position) const {
    Minimax minimax;
    const int idx = minimax.findBestMove(position);
    Position ret = position;
    if (idx > -1 && idx < 9) {
        ret[idx] = TileState::O;
    }
    return ret;
}