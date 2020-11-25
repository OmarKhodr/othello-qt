#include "othello.h"
#include <iostream>

using namespace std;

/**
 * @brief Othello::Othello, constructor
 * @file othello.h
 * Constructor that sets the initial state of the board and what player starts the game.
 */
Othello::Othello() {

    board = new QVector<QVector<int>*>();
    for (int i=0; i<8; i++) {
        QVector<int>* v = new QVector<int>();
        for (int j=0; j<8; j++) {
            v->append(-1);
        }
        board->append(v);
    }

    board->at(3)->replace(3, 1);
    board->at(4)->replace(4, 1);
    board->at(3)->replace(4, 0);
    board->at(4)->replace(3, 0);

    turn = 0;
}


/**
 * @brief Othello::playableCells, returns the coordinates of the cells that are playable.
 * @return QVector<QPair<int, int>>
 * @file othello.h
 */
QVector<QPair<int, int>> Othello::playableCells() {
    QVector<QPair<int, int>> res;

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (canPlay(i, j)) res.append( QPair<int, int>(i, j));
        }
    }

    return res;
}


/**
 * @brief Othello::canPlay
 * @param x
 * @param y
 * @return bool
 * @file othello.h
 * Checks if the cell at corrdinates (x,y) is available to be played.
 */
bool Othello::canPlay(int x, int y) {

    if (board->at(x)->at(y)!=-1){
        return false;
    }

    QPair<int, int> dirs[8] = {
        QPair<int,int>(-1, -1),
        QPair<int,int>(-1, 0),
        QPair<int,int>(-1, 1),
        QPair<int,int>(0, -1),
        QPair<int,int>(0, 1),
        QPair<int,int>(1, -1),
        QPair<int,int>(1, 0),
        QPair<int,int>(1, 1)
    };

    for (QPair<int, int> dir: dirs) {
        int i = x+dir.first;
        int j = y+dir.second;
        if (i<0 || i>=8 || j<0 || j>=8 || board->at(i)->at(j) != 1-turn) continue;

        while (i>=0 && i<8 && j>=0 && j<8) {
            if (board->at(i)->at(j) == turn) return true;
            i += dir.first;
            j += dir.second;
        }
    }

    return false;
}

/**
 * @brief Othello::play
 * @param x
 * @param y
 * @return turn
 * @file othello.h
 * Adds a chip to the (x,y) coordinate on the grid.
 */
int Othello::play(int x, int y) {
    board->at(x)->replace(y, turn);

    QPair<int, int> dirs[8] = {
        QPair<int,int>(-1, -1),
        QPair<int,int>(-1, 0),
        QPair<int,int>(-1, 1),
        QPair<int,int>(0, -1),
        QPair<int,int>(0, 1),
        QPair<int,int>(1, -1),
        QPair<int,int>(1, 0),
        QPair<int,int>(1, 1)
    };

    for (QPair<int, int> dir: dirs) {
        int i = x+dir.first;
        int j = y+dir.second;
        if (i<0 || i>=8 || j<0 || j>=8 || board->at(i)->at(j) != 1-turn) continue;

        bool valid = false;
        while (i>=0 && i<8 && j>=0 && j<8) {
            if (board->at(i)->at(j) == turn) {
                valid = true;
                break;
            }
            i += dir.first;
            j += dir.second;
        }
        if (!valid) continue;

        i = x+dir.first;
        j = y+dir.second;
        while (i>=0 && i<8 && j>=0 && j<8 && board->at(i)->at(j) == 1-turn) {
            board->at(i)->replace(j, turn);
            i += dir.first;
            j += dir.second;
        }
    }

    turn = 1-turn;
    if (playableCells().size() == 0) turn = 1-turn;

    return turn;
}


/**
 * @brief Othello::isGameOver
 * @return bool
 * @file othello.h
 * Checks if the game is over according to Othello rules
 */
bool Othello::isGameOver() {
    // Check if current player's turn has any valid moves
    if (playableCells().size() == 0) return true;

    // If any cells are empty then game *not* over
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board->at(i)->at(j) == -1) return false;
        }
    }

    return true;
}


/**
 * @brief Othello::winner
 * @return bool
 * @file othello.h
 * Counts the number of blue and red chips at the end of the game and decides the winner.
 */
int Othello::winner() {
    int white = 0;
    int black = 0;

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board->at(i)->at(j) == 1) white++;
            else if (board->at(i)->at(j) == 0) black++;
        }
    }

    if (white == black) return -1; // Draw
    else if (white > black) return 1; // White wins
    else return 0; // Black wins
}


/**
 * @brief Othello::print
 * @file othello.h
 * Prints the state of the board on the console, used for debugging
 */
void Othello::print() {
    QTextStream out(stdout);

    for (int j=0; j<8; j++) {
        out << j << " ";
    }
    out << endl;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board->at(i)->at(j) == -1) out << "_";
            else if (board->at(i)->at(j) == 1) out << "w";
            else out << "b";
            out << " ";
        }
        out << i << endl;
    }
}
