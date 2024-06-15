#include <iostream>
#include "entity.h"

Entity::Entity()
{
    
}
Entity::Entity(float x, float y)
{
    //spawnea en la posición (x,y)
    setTransform(x, y);
}
void Entity::Move(float x, float y)
{
    position.x += x;
    position.y += y;
}
void Entity::ToggleCollider()
{
    showCollider = !showCollider;
}