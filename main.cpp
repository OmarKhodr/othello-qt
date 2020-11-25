#include<QApplication>
#include <othelloview.h>
#include<QMainWindow>
#include <iostream>

using namespace std;

int main(int argc, char** argv){

    QApplication app(argc, argv);

    othelloView* view = new othelloView();
    view->show();

    /*
    QTextStream in(stdin);
    QTextStream out(stdout);

    Othello othello;
    while (!othello.isGameOver()) {
        othello.print();
        cout << (othello.turn == 1 ? "White" : "Black") << "'s turn. Choose move: " << endl;
        cout << endl;
        int i, j;
        cin >> i >> j;
        if (i<0 || i>=8 || j<0 || j>=8 || !othello.canPlay(i, j)) cout << "Invalid!" << endl;
        else othello.play(i, j);
    }
    out << "Winner is " << othello.winner();
    */

    return app.exec();
}
