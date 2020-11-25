#ifndef OTHELLOVIEW_H
#define OTHELLOVIEW_H

#include<QGraphicsView>

class othelloView : public QGraphicsView
{
    Q_OBJECT
public:
    othelloView();

    void centerWindow();
};

#endif // OTHELLOVIEW_H
