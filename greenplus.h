#ifndef GREENPLUS_H
#define GREENPLUS_H

#include <QObject>
#include <QGraphicsPixmapItem>

class greenplus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    greenplus();
};

#endif // GREENPLUS_H
