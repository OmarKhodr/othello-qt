#include "othelloscene.h"

/**
 * @brief othelloScene::othelloScene, constuctor that sets the scene
 * @file othelloscene.h
 */
othelloScene::othelloScene()
{
    setupBackground();
    setupWidgets();
    setupUpdateTimer();

}

/**
 * @brief othelloScene::setupBackground, sets the background image of the scene.
 * @file othelloscene.h
 */
void othelloScene::setupBackground(){
    setBackgroundBrush(QBrush(QImage(":/imagesOthello/800by952grid.png").scaledToWidth(800).scaledToHeight(952)));
    setSceneRect(0, 0, 800, 952);
    setFocus();
}

/**
 * @brief othelloScene::setupWidgets, sets up the turn labels
 * @file othelloscene.h
 */
void othelloScene::setupWidgets(){
    playerTurnLabel = new QLabel("PLayer turn: ");
    playerLabel = new QLabel("");

    playerTurnLabel->setStyleSheet("font: 35px;");

    QGraphicsProxyWidget* turnLabel = addWidget(playerTurnLabel);
    turnLabel->setPos(50, 850);

    QGraphicsProxyWidget* playerColorLabel = addWidget(playerLabel);
    playerColorLabel->setPos(300, 850);
}


/**
 * @brief othelloScene::setupUpdateTimer
 * @file othelloscene.h
 * Sets the timer that updates the scene at each timeout.
 */
void othelloScene::setupUpdateTimer(){
    updateTimer = new QTimer();
    QObject::connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateScene()));
    updateTimer->start(100);
}


/**
 * @brief othelloScene::updateScene
 * @file othelloscene.h
 * Slot that gets called at timer timeout, sets the current player turn, calls update to the cells
 * and to the available greenplus cells, and anounces winner when game is over.
 */
void othelloScene::updateScene(){
    // show which player's turn it is

    if (othello.turn==0){
        playerLabel->setText("RED");
        playerLabel->setStyleSheet("font: 50px;"
                                   "color: red;");
    }

    if (othello.turn==1){
        playerLabel->setText("BLUE");
        playerLabel->setStyleSheet("font: 50px;"
                                   "color: blue;");
    }

    // add updated cells
    updateCells();
    // add playable cells
    addPlayableCells();

    if(othello.isGameOver()){
        int win = othello.winner();
        if (win==-1){
            playerLabel->setText("DRAW");
            playerLabel->setStyleSheet("font: 80px;");
            return;
        }
        else if (win==0){
            playerLabel->setText("RED WINS");
            playerLabel->setStyleSheet("font: 80px;"
                                       "color: red;");
            return;
        }
        else if (win==1){
            playerLabel->setText("BLUE WINS");
            playerLabel->setStyleSheet("font: 80px;"
                                       "color: blue;");
            return;
        }
    }

}


// QMouseEvent function
/**
 * @brief othelloScene::mousePressEvent
 * @param event
 * @file othelloscene.h
 * When the player clicks left click on the mouse, it takes the coordinate of the mouse position when it was clicked
 * and checks if position is valid to insert the player's disk to the board.
 */
void othelloScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        int indexI;
        int indexJ;
        QPointF coor = event->scenePos();

        QString xcoor = QString::number(coor.x());
        QString ycoor = QString::number(coor.y());
        if (xcoor.length()<3){
            indexI = 0;
        }
        else {
            indexI = xcoor[0].digitValue();
        }
        if (ycoor.length()<3){
            indexJ = 0;
        }
        else {
            indexJ = ycoor[0].digitValue();
        }

        if (othello.canPlay(indexI, indexJ)){
        othello.play(indexI, indexJ);
        }
    }
}


/**
 * @brief othelloScene::addPlayableCells
 * @file othelloscene.h
 * Adds the pixmap green plus items to the available positions.
 */
void othelloScene::addPlayableCells(){

    // start by removing the previous greenplus items
    if (listOfPlayableCells.size()!=0){
        for (int i = 0  ; i<listOfPlayableCells.size(); i++){
            this->removeItem(listOfPlayableCells[i]);
        }
    }


    // now we get and add the new greenPlus items
    QVector<QPair<int, int>> vec = othello.playableCells();
    for (int j = 0 ; j<vec.size(); j++){
        QPair<int,int> p = vec[j];
        int xcoor = p.first*100+11;
        int ycoor = p.second*100+11;
        greenplus* item = new greenplus();
        listOfPlayableCells.push_back(item);
        addItem(item);
        item->setPos(xcoor, ycoor);
    }

}

/**
 * @brief othelloScene::updateCells
 * @file othelloscene.h
 * Updates the red and blue chips in the scene.
 */
void othelloScene::updateCells(){
    // start by removing the previous colored cells
    if (listOfUsedCells.size()!=0){
        for (int i = 0  ; i<listOfUsedCells.size(); i++){
            this->removeItem(listOfUsedCells[i]);
        }
    }
    int xcoor;
    int ycoor;
    QVector<QVector<int>*>* vec = othello.board;
    for (int i = 0 ; i<8; i++){
        for (int j = 0 ; j<8; j++){
            xcoor = i*100 + 8;
            ycoor = j*100 + 10;
            if (vec->at(i)->at(j)==1){
                blueChip* item = new blueChip();
                listOfUsedCells.push_back(item);
                addItem(item);
                item->setPos(xcoor, ycoor);
            }
            if (vec->at(i)->at(j)==0){
                redchip* item = new redchip();
                listOfUsedCells.push_back(item);
                addItem(item);
                item->setPos(xcoor, ycoor);
            }
        }
    }
}




