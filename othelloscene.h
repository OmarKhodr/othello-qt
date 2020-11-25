#ifndef OTHELLOSCENE_H
#define OTHELLOSCENE_H

#include "othello.h"
#include <QGraphicsScene>
#include <QtWidgets>
#include "greenplus.h"
#include "redchip.h"
#include "bluechip.h"

class othelloScene : public QGraphicsScene
{
    Q_OBJECT
public:
    othelloScene();

    Othello othello;
    QLabel* playerTurnLabel;
    QLabel* playerLabel;

    QTimer* updateTimer;

    QVector<QGraphicsItem*> listOfPlayableCells;
    QVector<QGraphicsItem*> listOfUsedCells;

private:
    void setupBackground();
    void setupWidgets();
    void setupUpdateTimer();
    void addPlayableCells();
    void updateCells();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private slots:
    void updateScene();
};

#endif // OTHELLOSCENE_H
