#ifndef BIRD_BLACK_H
#define BIRD_BLACK_H

#include <gameitem.h>
#include <bird.h>

class Bird_black:public Bird
{
public:
    Bird_black(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};


#endif // BIRD_BLACK_H

