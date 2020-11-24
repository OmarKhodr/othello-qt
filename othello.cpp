#include "othello.h"

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

QVector<QPair<int, int>*>* Othello::playableCells() {
    QVector<QPair<int, int>*>* res = new QVector<QPair<int, int>*>();

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (canPlay(i, j)) res->append(new QPair<int, int>(i, j));
        }
    }

    return res;
}

bool Othello::canPlay(int x, int y) {
    // If none of the adjacent cells are the opposite color or cell is already occupied, invalid
    int left = y > 0 ? board->at(x)->at(y-1) : -1;
    int right = y < 7 ? board->at(x)->at(y+1): -1;
    int top = x > 0 ? board->at(x-1)->at(y) : -1;
    int bottom = x < 7 ? board->at(x+1)->at(y): -1;
    int upRight = x > 0 && y < 7 ? board->at(x-1)->at(y+1) : -1;
    int upLeft = x > 0 && y > 0 ? board->at(x-1)->at(y-1) : -1;
    int downRight = x < 7 && y < 7 ? board->at(x+1)->at(y+1) : -1;
    int downLeft = x < 7 && y > 0 ? board->at(x+1)->at(y-1) : -1;

    bool valid = !(board->at(x)->at(y) != -1 ||
            (left != 1-turn
            && right != 1-turn
            && top != 1-turn
            && bottom != 1-turn
            && upRight != 1-turn
            && upLeft != 1-turn
            && downRight != 1-turn
            && downLeft != 1-turn));

    return valid;


}

int Othello::play(int x, int y) {
    board->at(x)->replace(y, turn); // place piece

    // "flank" horizontally to the right
    int j = y+1;
    while (j<8 && board->at(x)->at(j) == 1-turn) {
        board->at(x)->replace(j, turn);
        j++;
    }
    // "flank" horizontally to the left
    j = y-1;
    while (j>=0 && board->at(x)->at(j) == 1-turn) {
        board->at(x)->replace(j, turn);
        j--;
    }
    // "flank" vertically to the bottom
    int i = x+1;
    while (i<8 && board->at(i)->at(y) == 1-turn) {
        board->at(i)->replace(y, turn);
        i++;
    }
    // "flank" vertically to the top
    i = x-1;
    while (i>=0 && board->at(i)->at(y) == 1-turn) {
        board->at(i)->replace(y, turn);
        i--;
    }
    // "flank" diagonally top-right
    i = x-1;
    j = y+1;
    while (i>=0 && j<8 && board->at(i)->at(j) == 1-turn) {
        board->at(i)->replace(j, turn);
        i--;
        j++;
    }
    // "flank" diagonally top-left
    i = x-1;
    j = y-1;
    while (i>=0 && j>=0 && board->at(i)->at(j) == 1-turn) {
        board->at(i)->replace(j, turn);
        i--;
        j--;
    }
    // "flank" diagonally bottom-right
    i = x+1;
    j = y+1;
    while (i<8 && j<8 && board->at(i)->at(j) == 1-turn) {
        board->at(i)->replace(j, turn);
        i++;
        j++;
    }
    // "flank" diagonally bottom-left
    i = x+1;
    j = y-1;
    while (i<9 && j>=0 && board->at(i)->at(j) == 1-turn) {
        board->at(i)->replace(j, turn);
        i++;
        j--;
    }

    if (playableCells()->size() != 0) turn = 1-turn;

    return turn;
}

bool Othello::isGameOver() {
    // Check if current player's turn has any valid moves
    if (playableCells()->size() == 0) return true;

    // If any cells are empty then game *not* over
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board->at(i)->at(j) == -1) return false;
        }
    }

    return true;
}

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
