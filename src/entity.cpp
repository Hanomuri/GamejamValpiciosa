#include <iostream>
#include "entity.h"

Entity::Entity()
{
    
}
Entity::Entity(float x, float y)
{
    //spawnea en la posición (x,y)
    SetTransform(x, y);
}
void Entity::Move(float x, float y)
{
    m_transform.translation.x += x;
    m_transform.translation.y += y;
}
void Entity::ToggleCollider()
{
    showCollider = !showCollider;
}