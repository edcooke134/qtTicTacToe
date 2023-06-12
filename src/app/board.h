//
// Created by edc on 10.06.23.
//

#ifndef QTTICTACTOE_BOARD_H
#define QTTICTACTOE_BOARD_H

#include <QBasicTimer>
#include <QFrame>
#include "boardConfig.h"
#include "baseOpponent.h"
#include "drawer.h"

QT_BEGIN_NAMESPACE
class QPainter;
class QFrame;
class QWidget;
class QPaintEvent;
class QMouseEvent;
class QPoint;
QT_END_NAMESPACE

class Board : public QFrame {
Q_OBJECT

public:
    explicit Board(BaseOpponent *opponent, QWidget *parent = nullptr);

    ~Board();

    QSize sizeHint() const Q_DECL_OVERRIDE;

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;

public slots:

    void start();

    void reset();

    void setUserMovesFirst(bool);

    void setHardMode(bool);

    void userMovesFirstChanged(int);

    void hardModeChanged(int);

signals:

    void gameActiveChanged(bool);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    void clearBoard();

    QPoint getTileDimensions() const;

    bool won() const;

    void getComputerMove();

    int m_boardDimension = 15;
    Drawer m_drawer;
    bool m_gameActive = false;
    std::tuple<TileState, int, int> m_winner;
    BoardConfig *m_boardConfig = nullptr;
    BaseOpponent *m_opponent = nullptr;
};

#endif //QTTICTACTOE_BOARD_H
