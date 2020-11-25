#ifndef BLUECHIP_H
#define BLUECHIP_H

#include <QObject>
#include <QGraphicsPixmapItem>

class blueChip : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    blueChip();
};

#endif // BLUECHIP_H
