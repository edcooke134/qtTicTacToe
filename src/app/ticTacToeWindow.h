//
// Created by edc on 10.06.23.
//

#ifndef QTTICTACTOE_TICTACTOEWINDOW_H
#define QTTICTACTOE_TICTACTOEWINDOW_H

#include <QWidget>
#include "board.h"

QT_BEGIN_NAMESPACE
class QPushButton;
class QGroupBox;
class QCheckBox;
QT_END_NAMESPACE

class TicTacToeWindow : public QWidget {
Q_OBJECT

public:
    TicTacToeWindow() = delete;

    explicit TicTacToeWindow(BaseOpponent *opponent);

    ~TicTacToeWindow();

private:
    QGroupBox *createConfigGroup();

    Board *m_board = nullptr;

    QPushButton *m_startButton = nullptr;
    QPushButton *m_resetButton = nullptr;
    QPushButton *m_quitButton = nullptr;

    QGroupBox *m_configGroup = nullptr;
    QCheckBox *m_userMovesFirstCheckBox = nullptr;
    QCheckBox *m_hardModeCheckBox = nullptr;

};

#endif //QTTICTACTOE_TICTACTOEWINDOW_H
