#ifndef BIRD_BLUE_H
#define BIRD_BLUE_H

#include <gameitem.h>
#include <bird.h>

class Bird_blue:public Bird
{
public:
    Bird_blue(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};


#endif // BIRD_BLUE_H
