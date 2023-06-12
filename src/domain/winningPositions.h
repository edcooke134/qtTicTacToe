//
// Created by edc on 12.06.23.
//

#ifndef TICTACTOE_WINNINGPOSITIONS_H
#define TICTACTOE_WINNINGPOSITIONS_H
namespace winningPositions {
    const unsigned wp[8][3] = {{0, 1, 2},
                                      {3, 4, 5},
                                      {6, 7, 8},
                                      {0, 3, 6},
                                      {1, 4, 7},
                                      {2, 5, 8},
                                      {0, 4, 8},
                                      {2, 4, 6}};
} // namespace WinningPositions
#endif //TICTACTOE_WINNINGPOSITIONS_H
