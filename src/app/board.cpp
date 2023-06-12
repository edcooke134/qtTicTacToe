//
// Created by edc on 10.06.23.
//

#include <QtWidgets>
#include "board.h"

Board::Board(BaseOpponent *opponent, QWidget *parent)
        : m_opponent(opponent), QFrame(parent) {
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_boardConfig = new BoardConfig();
}

QSize Board::sizeHint() const {
    return QSize(m_boardDimension * 15 + frameWidth() * 2,
                 m_boardDimension * 15 + frameWidth() * 2);
}

QSize Board::minimumSizeHint() const {
    return QSize(m_boardDimension * 10 + frameWidth() * 2,
                 m_boardDimension * 10 + frameWidth() * 2);
}

void Board::start() {
    clearBoard();
    m_gameActive = true;
    emit gameActiveChanged(true);
    m_winner = {TileState::None, 0, 0};
    if (!m_boardConfig->getUserMovesFirst()) {
        getComputerMove();
    }
    update();
}

void Board::reset() {
    clearBoard();
    m_gameActive = false;
    emit gameActiveChanged(false);
    m_winner = {TileState::None, 0, 0};
    update();
}

void Board::userMovesFirstChanged(int state) {
    switch (state) {
        case 0: // box is unchecked
            setUserMovesFirst(false);
            break;
        case 2: // box is checked
            setUserMovesFirst(true);
            break;
        default:
            break;
    }
}

void Board::hardModeChanged(int state) {
    switch (state) {
        case 0: // box is unchecked
            setHardMode(false);
            break;
        case 2: // box is checked
            setHardMode(true);
            break;
        default:
            break;
    }
}

void Board::clearBoard() {
    if (m_boardConfig) {
        m_boardConfig->setPosition(std::vector<TileState>(9, TileState::None));
    }
}

void Board::setUserMovesFirst(bool userMovesFirst) {
    if (m_boardConfig) {
        m_boardConfig->setUserMovesFirst(userMovesFirst);
    }
}

void Board::setHardMode(bool hardMode) {
    if (m_boardConfig) {
        m_boardConfig->setHardMode(hardMode);
    }
}

void Board::mouseReleaseEvent(QMouseEvent *event) {
    if (m_gameActive && m_boardConfig && !won() && m_boardConfig->canMove()) {

        const auto pos = event->pos();
        const QPoint gridIdx = {
                pos.x() / getTileDimensions().x(),
                pos.y() / getTileDimensions().y()
        };

        const int idx = gridIdx.x() + 3 * gridIdx.y();
        if (idx < 0 || idx > 8) {
            return;
        }

        Position position = m_boardConfig->getPosition();
        if (position[idx] == TileState::None) {
            position[idx] = TileState::X;
            m_boardConfig->setPosition(position);
            m_winner = m_boardConfig->hasWon();
            update();
            if (won() || !m_boardConfig->canMove()) {
                update();
                return;
            }

            getComputerMove();
            m_winner = m_boardConfig->hasWon();
            update();
        }
    }
}

void Board::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    QPainter painter(this);

    m_drawer.drawGrid(painter, getTileDimensions());
    if (m_boardConfig) {
        m_drawer.drawTiles(painter, getTileDimensions(), m_boardConfig->getPosition());

        if (won()) {
            m_drawer.drawWinningLine(painter, getTileDimensions(), m_winner);
        }
    }
}

void Board::getComputerMove() {
    if (m_boardConfig && m_opponent) {
        m_boardConfig->setPosition(
                m_opponent->getNextMove(m_boardConfig->getPosition(), m_boardConfig->getHardMode()));
    }
}

QPoint Board::getTileDimensions() const {
    return QPoint(contentsRect().width(), contentsRect().height()) / 3.;
}

bool Board::won() const {
    return std::get<0>(m_winner) != TileState::None;
}

Board::~Board() {
    delete m_boardConfig;
}
