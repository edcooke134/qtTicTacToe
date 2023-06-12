//
// Created by edc on 10.06.23.
//

#include <QtWidgets>
#include "ticTacToeWindow.h"

TicTacToeWindow::TicTacToeWindow(BaseOpponent *opponent) {
    m_board = new Board(opponent, this);

    m_startButton = new QPushButton(tr("&Start"));
    m_startButton->setFocusPolicy(Qt::NoFocus);
    m_resetButton = new QPushButton(tr("&Reset"));
    m_resetButton->setFocusPolicy(Qt::NoFocus);
    m_quitButton = new QPushButton(tr("&Quit"));
    m_quitButton->setFocusPolicy(Qt::NoFocus);

    m_configGroup = createConfigGroup();

    connect(m_startButton, SIGNAL(clicked()), m_board, SLOT(start()));
    connect(m_resetButton, SIGNAL(clicked()), m_board, SLOT(reset()));
    connect(m_quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(m_userMovesFirstCheckBox, SIGNAL(stateChanged(int)), m_board, SLOT(userMovesFirstChanged(int)));
    connect(m_hardModeCheckBox, SIGNAL(stateChanged(int)), m_board, SLOT(hardModeChanged(int)));
    connect(m_board, SIGNAL(gameActiveChanged(bool)), m_configGroup, SLOT(setDisabled(bool)));
    connect(m_board, SIGNAL(gameActiveChanged(bool)), m_startButton, SLOT(setDisabled(bool)));

    auto *layout = new QGridLayout();
    layout->addWidget(m_board, 0, 0, 4, 4);
    layout->addWidget(m_startButton, 0, 4);
    layout->addWidget(m_resetButton, 1, 4);
    layout->addWidget(m_configGroup, 2, 4);
    layout->addWidget(m_quitButton, 3, 4);
    setLayout(layout);

    setWindowTitle(tr("TicTacToe"));
}

QGroupBox *TicTacToeWindow::createConfigGroup() {
    auto *groupBox = new QGroupBox(tr("Configuration:"));

    m_userMovesFirstCheckBox = new QCheckBox(tr("&Move First"), groupBox);
    m_userMovesFirstCheckBox->setChecked(true);
    m_hardModeCheckBox = new QCheckBox(tr("&Hard Mode"), groupBox);
    m_hardModeCheckBox->setChecked(false);

    auto *vbox = new QVBoxLayout();
    vbox->addWidget(m_userMovesFirstCheckBox);
    vbox->addWidget(m_hardModeCheckBox);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

TicTacToeWindow::~TicTacToeWindow() {
    delete m_board;
    delete m_startButton;
    delete m_resetButton;
    delete m_quitButton;
    delete m_userMovesFirstCheckBox;
    delete m_hardModeCheckBox;
    delete m_configGroup;
}