#ifndef ARROW_H
#define ARROW_H

#include <gameitem.h>
#include <QGraphicsScene>

class Arrow : public GameItem
{
public:
    Arrow(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // ARROW_H
