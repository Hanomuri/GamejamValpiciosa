#pragma once

#include "core.h"
#include "entity.h"
#include "raylib.h"
#include "todo.h"

typedef struct Player : Entity {
  using Entity::ToggleCollider;
  Camera2D m_camera = {0, 0, 0, 0, 0, 0};
  TileCollider collider = {"resources/data/collisionMap.data"};
  Todo todo = {};

  Player();
  void Move(float x, float y, int tX, int tY);
  void SetCamera();
  void Update();
} Player;
