//
// Created by edc on 10.06.23.
//
#include <algorithm>
#include "boardConfig.h"

BoardConfig::BoardConfig() noexcept:
        m_position(std::vector<TileState>(9, TileState::None)), m_hardMode(false), m_userMovesFirst(true) {}

void BoardConfig::setPosition(Position position) {
    m_position = std::move(position);
}

Position BoardConfig::getPosition() const {
    return m_position;
}

std::tuple<TileState, int, int> BoardConfig::hasWon() const {
    unsigned wins[8][3] = {{0, 1, 2},
                           {3, 4, 5},
                           {6, 7, 8},
                           {0, 3, 6},
                           {1, 4, 7},
                           {2, 5, 8},
                           {0, 4, 8},
                           {2, 4, 6}};
    for (auto &win: wins) {
        if (m_position[win[0]] != TileState::None &&
            m_position[win[0]] == m_position[win[1]] &&
            m_position[win[1]] == m_position[win[2]]) {
            return {m_position[win[2]], win[0], win[2]};
        }
    }
    return {TileState::None, 0, 0};
}


bool BoardConfig::canMove() const {
    return std::find(m_position.begin(), m_position.end(), TileState::None) != m_position.end();
}

void BoardConfig::setHardMode(bool hardMode) noexcept {
    m_hardMode = hardMode;
}

bool BoardConfig::getHardMode() const noexcept {
    return m_hardMode;
}

void BoardConfig::setUserMovesFirst(bool userMovesFirst) noexcept {
    m_userMovesFirst = userMovesFirst;
}

bool BoardConfig::getUserMovesFirst() const noexcept {
    return m_userMovesFirst;
}