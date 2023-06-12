//
// Created by edc on 10.06.23.
//

#ifndef TICTACTOE_BOARDCONFIG_H
#define TICTACTOE_BOARDCONFIG_H

#include <vector>
#include <optional>

enum class TileState {
    None,
    X,
    O
};

using Position = std::vector<TileState>;

class BoardConfig {
public:
    BoardConfig() noexcept;

    void setPosition(Position);

    Position getPosition() const;

    std::tuple<TileState, int, int> hasWon() const;

    bool canMove() const;

    void setHardMode(bool) noexcept;

    bool getHardMode() const noexcept;

    void setUserMovesFirst(bool) noexcept;

    bool getUserMovesFirst() const noexcept;

private:
    Position m_position;
    bool m_hardMode = false;
    bool m_userMovesFirst = true;
};

#endif //TICTACTOE_BOARDCONFIG_H
