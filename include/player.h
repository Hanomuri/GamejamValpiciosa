#pragma once

#include "entity.h"
#include "raylib.h"
#include "todo.h"

typedef struct Player : Entity {
  using Entity::Move, Entity::ToggleCollider;
  Camera2D m_camera = {0, 0, 0, 0, 0, 0};
  Todo todo = {};
  int dangerLevel = 0;
  Player();
  void SetCamera();
  void Update();
} Player;
