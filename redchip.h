#ifndef REDCHIP_H
#define REDCHIP_H

#include <QObject>
#include <QGraphicsPixmapItem>
class redchip : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    redchip();
};

#endif // REDCHIP_H
