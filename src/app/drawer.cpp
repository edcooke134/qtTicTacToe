//
// Created by edc on 12.06.23.
//
#include "drawer.h"

void Drawer::drawGrid(QPainter &painter, QPoint tileDim) {
    const auto color = QColor(0, 0, 0, 255);
    painter.setPen(color.dark());

// dimension of one grid tile
    painter.drawLine(tileDim.x() * 1, tileDim.y() * 0, tileDim.x() * 1, tileDim.y() * 3);
    painter.drawLine(tileDim.x() * 2, tileDim.y() * 0, tileDim.x() * 2, tileDim.y() * 3);
    painter.drawLine(tileDim.x() * 0, tileDim.y() * 1, tileDim.x() * 3, tileDim.y() * 1);
    painter.drawLine(tileDim.x() * 0, tileDim.y() * 2, tileDim.x() * 3, tileDim.y() * 2);
}

void Drawer::drawTiles(QPainter &painter, QPoint tileDim, const Position &position) {
    for (int idx = 0; idx < position.size(); ++idx) {
        if (position[idx] == TileState::X) {
            drawX(painter, tileDim, idx);
        } else if (position[idx] == TileState::O) {
            drawO(painter, tileDim, idx);
        }
    }
}

void Drawer::drawX(QPainter &painter, QPoint tileDim, int idx) {
    const auto color = QColor(255, 45, 0, 255);
    QPen pen = QPen(color);
    pen.setWidth(3);
    painter.setPen(pen);

    const QPoint tile = getTile(idx);

    painter.drawLine(tile.x() * tileDim.x(), tile.y() * tileDim.y(), (tile.x() + 1) * tileDim.x(),
                     (tile.y() - 1) * tileDim.y());
    painter.drawLine(tile.x() * tileDim.x(), (tile.y() - 1) * tileDim.y(), (tile.x() + 1) * tileDim.x(),
                     tile.y() * tileDim.y());
}

void Drawer::drawO(QPainter &painter, QPoint tileDim, int idx) {
    const auto color = QColor(160, 255, 140, 255);
    QPen pen = QPen(color.dark());
    pen.setWidth(3);
    painter.setPen(pen);

    const QPoint tile = getTile(idx);

    painter.drawEllipse(tile.x() * tileDim.x(), (tile.y() - 1) * tileDim.y(), tileDim.x(), tileDim.y());
}

void Drawer::drawWinningLine(QPainter &painter, QPoint tileDim, const std::tuple<TileState, int, int> &lineIndices) {
    const auto color = QColor(0, 107, 255, 255);
    QPen pen = QPen(color);
    pen.setWidth(5);
    painter.setPen(pen);


    QPoint start = getTile(std::get<1>(lineIndices));
    start = QPoint((start.x() + 0.5) * tileDim.x(), (start.y() - 0.5) * tileDim.y());
    QPoint end = getTile(std::get<2>(lineIndices));
    end = QPoint((end.x() + 0.5) * tileDim.x(), (end.y() - 0.5) * tileDim.y());

    painter.drawLine(start, end);

}

// gets the bottom left point of the tile in the grid indexed idx = [0,8]
QPoint Drawer::getTile(int idx) const {
    const int x = idx % 3;
    const int y = static_cast<int>(round((idx - x) / 3.));
    return {x, y + 1};
}