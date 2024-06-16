#pragma once

#include "entity.h"
#include "todo.h"

typedef struct NPC : Entity {
  Todo todo = {};
  int dangerLevel = 0;
  bool hasPills = false;

  bool hasTask1 = false;
  bool hasTask2 = false;
  bool hasTask3 = false;
  bool hasTask4 = false;
  bool completedTask1 = false;
  bool completedTask2 = false;
  bool completedTask3 = false;
  bool completedTask4 = false;
};
