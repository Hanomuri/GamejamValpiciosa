#pragma once

#include <raylib.h>

class Entity
{
    private:
        bool isHostile;
        bool showCollider;
        Transform m_transform;
    public:
        Entity();
        Entity(float xPos, float yPos);

        //mueve el personaje +x y +y desde su posición actual
        void Move(float xOffset, float yOffset);

        //teleport to (x,y)
        void MoveToPos(float xOffset, float yOffset);
        //wtf is a kilometer
        void ToggleCollider();

        Transform* GetTransform() {return &m_transform;}
     protected :
        void SetTransform(float x, float y)
        {
            m_transform.translation = {x, y, 0};
        }

};
