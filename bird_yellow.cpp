#include "bird_yellow.h"

Bird_yellow::Bird_yellow(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene): Bird(x, y, radius, timer, pixmap, world, scene){

}


void Bird_yellow::skill()
{
    setAngularVelocity(5000);
    //setLinearVelocity(b2Vec2(10,-10));

}
