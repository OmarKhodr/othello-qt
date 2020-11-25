#include "othelloview.h"

#include "othelloscene.h"

othelloView::othelloView()
{
    setFixedSize(800, 952);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    othelloScene* scene = new othelloScene();
    setScene(scene);

    centerWindow();
}

void othelloView::centerWindow(){
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
}
