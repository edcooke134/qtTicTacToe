//
// Created by edc on 10.06.23.
//

#include <QtWidgets>
#include "ticTacToeWindow.h"
#include "opponentImpl.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    BaseOpponent *opponentImpl = new OpponentImpl();
    TicTacToeWindow window(opponentImpl);
    window.show();
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    const int r = app.exec();
    delete opponentImpl;
    return r;
}
