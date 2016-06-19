#ifndef BIRD_RED_H
#define BIRD_RED_H

#include <gameitem.h>
#include <bird.h>

class Bird_red:public Bird
{
public:
    Bird_red(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};


#endif // BIRD_RED_H
