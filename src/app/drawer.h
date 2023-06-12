//
// Created by edc on 12.06.23.
//

#ifndef TICTACTOE_DRAWER_H
#define TICTACTOE_DRAWER_H

#include <QPainter>
#include <cmath>
#include "boardConfig.h"

class Drawer {
public:
    void drawGrid(QPainter &painter, QPoint tileDim);

    void drawTiles(QPainter &painter, QPoint tileDim, const Position &position);

    void drawX(QPainter &painter, QPoint tileDim, int idx);

    void drawO(QPainter &painter, QPoint tileDim, int idx);

    void drawWinningLine(QPainter &painter, QPoint tileDim, const std::tuple<TileState, int, int> &lineIndices);

    QPoint getTile(int idx) const;
};

#endif //TICTACTOE_DRAWER_H
