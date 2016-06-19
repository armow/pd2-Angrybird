#include "bird_blue.h"

Bird_blue::Bird_blue(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene): Bird(x, y, radius, timer, pixmap, world, scene){

}


void Bird_blue::skill()
{
    setLinearVelocity(b2Vec2(50,-100));

}
