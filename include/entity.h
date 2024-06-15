#pragma once


#include <raylib.h>

class Entity
{
    private:
        bool isHostile;
        bool showCollider;
        Vector2 position;
        void setTransform(float x, float y)
        {
            position = {x, y};
        }
    public:
        Entity();
        Entity(float xPos, float yPos);

        //mueve el personaje +x y +y desde su posición actual
        void Move(float xOffset, float yOffset);

        //teleport to (x,y)
        void MoveToPos(float xOffset, float yOffset);
        //teleport to (x,y)
        void ToggleCollider();
};