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
    int moveCounter;

    QVector<QPair<int, int>*>* playableCells();
    bool canPlay(int x, int y);
    int play(int x, int y); // returns the player number whose number is next.
    bool isGameOver();
    int winner();
    void print();

};

#endif // OTHELLO_H
