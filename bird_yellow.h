#ifndef BIRD_YELLOW_H
#define BIRD_YELLOW_H

#include <gameitem.h>
#include <bird.h>

class Bird_yellow:public Bird
{
public:
    Bird_yellow(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};


#endif // BIRD_YELLOW_H
