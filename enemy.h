#ifndef ENEMY_H
#define ENEMY_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class Enemy : public GameItem
{
public:
    Enemy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    //void setLinearVelocity(b2Vec2 velocity);
    b2Vec2 getLinearVelocity();
};

#endif // ENEMY_H
