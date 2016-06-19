#include "bird_black.h"

Bird_black::Bird_black(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene): Bird(x, y, radius, timer, pixmap, world, scene){

}


void Bird_black::skill()
{
    setLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x*100,g_body->GetLinearVelocity().y*100));

}
