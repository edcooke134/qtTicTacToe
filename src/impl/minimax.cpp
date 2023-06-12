//
// Created by edc on 12.06.23.
//
#include "minimax.h"
#include "winningPositions.h"

// evaluate if there is a winner
int Minimax::evaluate(const Position &position) {
    using namespace winningPositions;
    for (int i = 0; i < 8; ++i) {
        if (position[wp[i][0]] != TileState::None &&
            position[wp[i][0]] == position[wp[i][1]] && position[wp[i][1]] == position[wp[i][2]]) {
            return position[wp[i][2]] == TileState::X ? -1 : 1;
        }
    }
    return 0;
}

// minimax algorithm
int Minimax::minimax(Position position, int player) {
    int winner = evaluate(position);

    if (winner != 0) {
        return winner * player;
    }

    int move = -1;
    int score = -2;

    for (int i = 0; i < 9; i++) {
        if (position[i] == TileState::None) {

            position[i] = player == -1 ? TileState::X : TileState::O;
            int thisScore = -minimax(position, player * -1);

            if (thisScore > score) {
                score = thisScore;
                move = i;
            }
            position[i] = TileState::None;
        }
    }
    if (move == -1) {
        return 0;
    }

    return score;
}

// find the best possible move, given the current position
int Minimax::findBestMove(Position position) {
    int score = -2;
    int bestMove = -1;

    for (int idx = 0; idx < position.size(); ++idx) {
        {
            // Check if the tile is empty
            if (position[idx] == TileState::None) {
                // Make the move
                position[idx] = TileState::O;
                // run the minimax algorithm
                int tempScore = -minimax(position, -1);
                // Revert the move
                position[idx] = TileState::None;

                // keep track of the best score and update the index accordingly
                if (tempScore > score) {
                    bestMove = idx;
                    score = tempScore;
                }
            }
        }
    }
    return bestMove;
}