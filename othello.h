#ifndef OTHELLO_H
#define OTHELLO_H

#include <QObject>
#include <QVector>
#include <QTextStream>

class Othello {
    Q_GADGET;
public:
    Othello();

    QVector<QVector<int>*>* board;
    int turn;

    QVector<QPair<int, int>*>* playableCells(); // Returns vector of cells where current player can place his piece.
    bool canPlay(int x, int y); // DONT'T USE: returns true if current player can place a piece in this cell, false otherwise.
    int play(int x, int y); // Places piece at cell, assumes cell is valid. Returns the player number whose turn is next.
    bool isGameOver(); // Returns true if no more moves can be made by either players, false otherwise.
    int winner(); // To be called after isGameOver() returns true. Returns player with higher piece count.
    void print(); // CONSOLE ONLY: prints board on console.

};

#endif // OTHELLO_H
