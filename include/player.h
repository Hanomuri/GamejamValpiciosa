#pragma once

#include "core.h"
#include "entity.h"
#include "raylib.h"
#include "todo.h"

typedef struct Player : Entity {
  using Entity::ToggleCollider;
  Camera2D m_camera = {0, 0, 0, 0, 0, 0};
  TileCollider collider = {"resources/data/0/collisionMap0.data"};
  Todo todo = {};
  int dangerLevel = 0;
  bool hasPills = false;

  void TogglePills() {hasPills = !hasPills;}
  bool hasTask1 = false;
  bool hasTask2 = false;
  bool hasTask3 = false;
  bool hasTask4 = false;
  bool completedTask1 = false;
  bool completedTask2 = false;
  bool completedTask3 = false;
  bool completedTask4 = false;

  Player();
  void Move(float x, float y, int tX, int tY);
  void SetCamera();
  void Update();
} Player;
