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

  SpriteSheet sprite = {"resources/images/Entities/Protagonista.png", 10, 1};
  Animation rightIdle = {"rightIdle", sprite, 0, 2, 2.0f};
  Animation rightMove = {"rightMove", sprite, 1, 2, 2.0f};
  Animation leftIdle = {"leftIdle", sprite, 3, 2, 2.0f};
  Animation leftMove = {"leftMove", sprite, 4, 2, 2.0f};
  Animation upIdle = {"upIdle", sprite, 6, 1, 2.0f};
  Animation upMove = {"upMove", sprite, 7, 4, 2.0f};

  Animation* animationsArray[6] = {&rightIdle,
                                  &rightMove,
                                  &leftIdle,
                                  &leftMove,
                                  &upIdle,
                                  &upMove};
  Animator m_animator = {*animationsArray, 6};

  unsigned int rIdleN[6] = {0, 1, 2, 3, 4, 5};       //0
  unsigned int rMoveN[6] = {0, 1, 2, 3, 4, 5};      //1
  unsigned int lIdleN[6] = {0, 1, 2, 3, 4, 5};          //2
  unsigned int lMoveN[6] = {0, 1, 2, 3, 4, 5};          //3
  unsigned int uIdleN[6] = {0, 1, 2, 3, 4, 5};          //4
  unsigned int uMoveN[6] = {0, 1, 2, 3, 4, 5};       //5

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
