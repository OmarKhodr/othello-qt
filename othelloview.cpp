#include "othelloview.h"

#include "othelloscene.h"

/**
 * @brief othelloView::othelloView
 * @file othelloview.h
 * Constructor that adds the othelloscene to the view.
 */
othelloView::othelloView()
{
    setFixedSize(800, 952);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    othelloScene* scene = new othelloScene();
    setScene(scene);

    centerWindow();
}

/**
 * @brief othelloView::centerWindow, centers window to the middle of the screen
 * @file othelloview.h
 */
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
